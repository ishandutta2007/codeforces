#include <bits/stdc++.h>
using namespace std;
const int maxn = 10e5 + 120;
int m,q;
struct SegmentTree{
    pair<int,int> Max[maxn];
    void up(int x){
        Max[x] = max(Max[x<<1],Max[x<<1|1]);
    }
    void build(int x,int l,int r){
        if (l == r){
            Max[x] = {0,-l};
            return;
        }
        int mid = l + r >> 1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        up(x);
    }
    void add(int x,int l,int r,int pos,int del){
        if (l == r){
            Max[x].first += del;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid)add(x<<1,l,mid,pos,del);
        else add(x<<1|1,mid+1,r,pos,del);
        up(x);
    }
    pair<int,int> query(int x,int l,int r,int L,int R){
        if (l > R or L > r)return {-1,-1};
        if (L <= l and r <= R)return Max[x];
        int mid = l + r >> 1;
        return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
}segtree;
pair<int,int> ans[maxn];
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    int sz[maxn*2];
    int wson[maxn*2];
    int pos[maxn];
    bool big[maxn*2];
    vector<int> E[maxn*2];
    vector<int> Label[maxn*2];
    int st[maxn*2][21];
    vector<tuple<int,int,int> > Query[maxn*2];
    Suffix_Automaton(){
        clear();
    }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void _dfs(int u,int father){
        st[u][0] = father;
        sz[u] = 1;
        for (int i=1;i<=20;i++){
            st[u][i] = st[st[u][i-1]][i-1];
        }
        for (int v : E[u]){
            _dfs(v,u);
            sz[u] += sz[v];
            if (sz[v] > sz[wson[u]]){
                wson[u] = v;
            }
        }
    }
    void add(int u,int sign){
        for (int label : Label[u])
            segtree.add(1,1,m,label,sign);
        for (int v : E[u]){
            if (big[v])continue;
            add(v,sign);
        }
    }
    void dfs(int u,bool keep){
        for (int v : E[u]){
            if (v == wson[u])continue;
            dfs(v,0);
        }
        if (wson[u]){
            big[wson[u]]=1;
            dfs(wson[u],1);
        }
        add(u,1);
        for (auto q:Query[u]){
            int l,r,id;
            tie(l,r,id) = q;
            ans[id] = segtree.query(1,1,m,l,r);
        }
        if (wson[u])big[wson[u]] = 0;
        if (!keep)add(u,-1);
    }
    void gao(){
        segtree.build(1,1,m);
        dfs(1,0);
    }
    void init(const char *s){
        int n = strlen(s);
        for (int i=0;i<n;i++){
            add(s[i]-'a');
        }
    }
    void build(const char *s){
        int n = strlen(s);
        int now = 1;
        for (int i=0;i<n;i++){
            pos[i+1] = now = nxt[now][s[i] - 'a'];
        }
        for (int i=2;i<=cnt;i++){
            E[fa[i]].push_back(i);
        }
        _dfs(1,0);
    }
    void run(const char *s,int label){
        int n = strlen(s);
        int now = 1;
        for (int i=0;i<n;i++){
            while (now != 1 and !nxt[now][s[i] - 'a'])now = fa[now];
            if (nxt[now][s[i] - 'a'])now = nxt[now][s[i] - 'a'];
            Label[now].push_back(label);
        }
    }
    int locate(int l,int r){
        int now = pos[r];
        int len = r - l + 1;
        for (int i=20;i>=0;i--){
            int t = st[now][i];
            if (t and this->l[fa[t]] + 1 > len){
                now = t;
            }
        }
        if (this->l[fa[now]] + 1 <= len)return now;
        else return st[now][0];
    }
    void add_query(int l,int r,int pl,int pr,int id){
        int u = locate(pl,pr);
        //cerr<<id<<": "<< u<<endl;
        Query[u].push_back(make_tuple(l,r,id));
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p]+1;last = np;
        while (p&&!nxt[p][c])nxt[p][c] = np,p = fa[p];
        if (!p)fa[np]=1;
        else{
            int q = nxt[p][c];
            if (l[q]==l[p]+1)fa[np] =q;
            else{
                int nq = ++ cnt;
                l[nq] = l[p]+1;
                memcpy(nxt[nq],nxt[q],sizeof (nxt[q]));
                fa[nq] =fa[q];fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
}sam;
vector<string> dict;
int main(){
    static char buf[maxn];
    scanf("%s",buf);
    sam.init(buf);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        string S;
        cin>>S;
        dict.push_back(S);
        sam.last = 1;
        sam.init(S.c_str());
//        scanf("%s",buf);
        //sam.run(buf,i);
    }
    for (int i=0;i<m;i++){
        sam.run(dict[i].c_str(),i+1);
    }
    sam.build(buf);
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        int l,r,pl,pr;
        scanf("%d%d%d%d",&l,&r,&pl,&pr);
        sam.add_query(l,r,pl,pr,i);
    }
    sam.gao();
    for (int i=1;i<=q;i++){
        printf("%d %d\n",-ans[i].second,ans[i].first);
    }
    return 0;
}
/*
suffixtree
3
suffixtreesareawesome
cartesiantreeisworsethansegmenttree
nyeeheeheee
2
1 2 1 10
1 3 9 10

*/