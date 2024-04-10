#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;

struct LinkCut {
    struct node{
        int p = 0, ch[2] = {0, 0}, pp = 0, sz = 0;
        int val = 1e9, min = 1e9;
        bool flip = 0;
    };
    vector<node> T;
    
    LinkCut(int n): T(n+1){ }
    
    int dir(int x, int y){ //which ch[?] y is of x
        return T[x].ch[1] == y;
    }
    
    void set(int x, int d, int y){ //set x's ch[d] to y and y's par to x
        if(x) T[x].ch[d] = y, pull(x);
        if(y) T[y].p = x;
    }
    
    void pull(int x){
        if(!x) return;
        int l = T[x].ch[0], r = T[x].ch[1];
        push(l), push(r);
        T[x].min = min({T[x].val, T[l].min, T[r].min});
        T[x].sz = T[l].sz + T[r].sz + 1;
    }
    
    void push(int x){
        if(!x) return;
        int &l = T[x].ch[0], &r = T[x].ch[1];
        if(T[x].flip){
            swap(l, r);
            T[l].flip ^= 1; T[r].flip ^= 1;
            T[x].flip = 0;
        }
    }
    
    void rotate(int x, int d){ // 0 left, 1 right
        int y = T[x].p, z = T[y].p, w = T[x].ch[d];
        swap(T[x].pp, T[y].pp);
        set(y, !d, w);
        set(x, d, y);
        set(z, dir(z, y), x);
    }
    
    void splay(int x){
        for(push(x); T[x].p;){
            int y = T[x].p, z = T[y].p;
            push(z); push(y); push(x);
            int dx = dir(y, x), dy = dir(z, y);
            if(!z)
                rotate(x, !dx);
            else if(dx == dy)
                rotate(y, !dx), rotate(x, !dx); // zig zag
            else
                rotate(x, dy), rotate(x, dx); // zig zig
        }
    }
    
    // SPLAY TREE OPERATIONS END
    
    void makeroot(int u){
        access(u);
        int l = T[u].ch[0];
        T[l].flip ^= 1;
        swap(T[l].p, T[l].pp);
        set(u, 0, 0);
    }
    
    int access(int _u){
        int v, u;
        for(v = 0, u = _u; u; u = T[v = u].pp){ // jump both up (u is pp of v)
            splay(u); splay(v);
            //remove u's prefered child (r), change to v if it exists
            int r = T[u].ch[1];
            T[v].pp = 0;
            swap(T[r].p, T[r].pp);
            set(u, 1, v);
        }
        splay(_u);
        return v; // last node that pp jumped to (for lca)
    }
    
    void link(int u, int v){ // make v's parent u
        if(connected(u, v))
            return;
        makeroot(v);
        T[v].pp = u;
    }
    
    void cut(int u, int v){
        makeroot(u); access(u); splay(v);
        assert(T[v].pp == u);
        T[v].pp = 0;
    }
    
    void cutup(int u, int root){
        makeroot(root);
        access(u);
        if(!T[u].ch[0])
            return;
        cut(u, T[u].ch[0]);
    }
    
    bool connected(int u, int v){
        if(u == v) return 1;
        makeroot(u); access(v); splay(u);
        return T[v].p == u || T[T[v].p].p == u;
    }
    
    node query(int u, int v){
        makeroot(u); access(v);
        //now v is at top of ALL and only nodes in the splay are on path root(u) -> v
        //so it becomes subtree sum
        return T[v];
    }
    
    // void update(int v, int x){
        // makeroot(v), access(v);
        // T[v].val = v;
    // }
    
    int findroot(int u){
        access(u);
        while(T[u].ch[0])
            u = T[u].ch[0];
        splay(u);
        return u;
    }
};

const int MM = 6e5+5;
LinkCut LCT(MM);

int n, m, q, ans[MM], a[MM], b[MM];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>n>>m>>q;
    
    for(int i = 1; i <= m; i++){
        cin>>a[i]>>b[i];
        a[m+i] = a[i];
        b[m+i] = b[i];
        LCT.T[n+i].val = LCT.T[n+i].min = i;   
        LCT.T[n+m+i].val = LCT.T[n+m+i].min = m+i;   
    }

    for(int l = 1, r = 1; l <= 2*m; l++){
        while(r <= 2*m){
            if(!LCT.connected(a[r], b[r])){
                // pr("link", a[r], b[r], r);
                LCT.link(a[r], n+r);
                LCT.link(b[r], n+r);
                r++;
                continue;
            }
            else{
                auto ret = LCT.query(a[r], b[r]);
                int id = ret.min;
                // pr("id", id, "len", (ret.sz+1)/2 % 2);
                if((ret.sz+1)/2 % 2 == 0){
                    // if the path is even length, remove lowest l to replace with current edge
                    // pr("cut", a[id], b[id], id);
                    LCT.cut(a[id], n+id);
                    LCT.cut(b[id], n+id);
                    // pr("link", a[r], b[r], r);
                    LCT.link(a[r], n+r);
                    LCT.link(b[r], n+r);
                    r++;
                    continue;
                }
            }
            break;
        }
        ans[l] = r;
        // can take up to [l, r) and still be bipartite
        if(LCT.connected(a[l], n+l)){
            LCT.cut(a[l], n+l);
            LCT.cut(b[l], n+l);
        }
    }

    // for(int i = 0; i <= m; i++) cerr<<ans[i]<<' '; cerr<<endl;

    while(q--){
        int l, r; cin>>l>>r;
        // (r, l+m)
        // I take [r+1, l+m-1]
        r++;
        l += m-1;
        if(l < ans[r]){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}