#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+100;
char s[maxn];int n;
int a,b;
struct Chairman_Tree{
    int cnt = 0;
    int root[maxn*2];
    struct Node{int L,R,val;}tree[maxn*32];
    void init(){
        memset(root,0,sizeof root);
        cnt =0;
    }
    /* T0 */
    int buildT0(int l, int r){
        int k = cnt++;
        tree[k].val =0;
        if (l==r) return k;
        int mid = l+r >>1;
        tree[k].L = buildT0(l, mid);tree[k].R = buildT0(mid + 1, r);
        return k;
    }
    /* Pppos+=del */
    int update (int P,int l,int r,int ppos,int del){
        //assert(cnt < maxn*50);
        int k = cnt++;
        tree[k].val = tree[P].val +del;
        if (l==r) return k;
        int mid = l+r >>1;
        if (ppos<=mid){
            tree[k].L = update(tree[P].L,l,mid,ppos,del);
            tree[k].R = tree[P].R;
        }else{
            tree[k].L = tree[P].L;
            tree[k].R = update(tree[P].R,mid+1,r,ppos,del);
        }
        return k;
    }
    int query(int PL,int PR,int l,int r,int L,int R){
        if (l>R || L>r)return 0;
        if (L <= l && r <= R)return tree[PR].val - tree[PL].val;
        int mid = l + r >> 1;
        return query(tree[PL].L,tree[PR].L,l,mid,L,R) + query(tree[PL].R,tree[PR].R,mid+1,r,L,R);
    }
}tree;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    int end_pos[maxn*2];
    vector<int> E[maxn*2];
    int dfsl[maxn*2],dfsr[maxn*2],dfn;
    int pos[maxn*2];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        //fa[1]=l[1]=0;
        //memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');s++;
        }
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        //memset(nxt[cnt],0,sizeof nxt[cnt]);
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
    void build(){
        int temp = 1;
        for (int i=1;i<=n;i++){
            temp = nxt[temp][s[i] - 'a'];
            end_pos[temp] = i;
        }
        for (int i=2;i<=cnt;i++){
            E[fa[i]].push_back(i);
        }
    }
    void dfs(int u){
        dfsl[u] = ++ dfn;
        pos[dfn] = u;
        for (int v : E[u]){
            dfs(v);
        }
        dfsr[u] = dfn;
    }
    void main(){
        dfn = 0;
        dfs(1);
        tree.root[0] = tree.buildT0(1,n);
        for (int i=1;i<=cnt;i++){
            int u = pos[i];
            if (end_pos[u]){
                int idx = end_pos[u];
                tree.root[i] = tree.update(tree.root[i-1],1,n,idx,1);
            }else{
                tree.root[i] = tree.root[i-1];
            }
        }
    }
    void debug(){
        for (int i=1;i<=cnt;i++){
            for (int v : E[i]){
                cerr<<i<<"->"<<v<<endl;
            }
        }
        for (int i=1;i<=cnt;i++){
            if (end_pos[i]){
                cerr<<i<<":"<<end_pos[i]<<endl;
            }
        }
        for (int i=1;i<=cnt;i++){
            for (int j=0;j<26;j++){
                if (nxt[i][j]){
                    cerr<<i<<"["<<(char)(j+'a')<<"]="<<nxt[i][j]<<endl;
                }
            }
        }
    }
}sam;
struct Node{
    int R;
    int dp_val;
    bool operator < (const Node& other)const{
        return other.dp_val < dp_val;
    }
};
inline bool in_range(int x,int y,int z){
    return x <= y && y <=z;
}
int dp[maxn];
int main(){
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    sam.init(s+1);
    sam.build();
    sam.main();
    //sam.debug();
    priority_queue<Node> pq;
    for (int i=1,j=1,temp = 1;i<=n;i++){
        if (j < i){
            j = i;
            temp = 1;
        }
        if (j >= i){
            int len = j - i;
            while (temp != 1 && !in_range(sam.l[sam.fa[temp]]+1,len,sam.l[temp])){
                temp = sam.fa[temp];
            }
        }
        while (j <n && sam.nxt[temp][s[j+1] - 'a'] &&
            tree.query(tree.root[sam.dfsl[sam.nxt[temp][s[j+1] - 'a']]-1],tree.root[sam.dfsr[sam.nxt[temp][s[j+1] - 'a']]],1,n,1,i)){
            //int Nxt = sam.nxt[temp][s[j+1] - 'a'];
            //int L = sam.dfsl[sam.nxt[temp][s[j+1] - 'a']];
            //int R = sam.dfsr[sam.nxt[temp][s[j+1] - 'a']];
            //cerr<<i<<" "<<Nxt<<" "<<L<<" "<<R<<endl;
            //cerr<<tree.query(tree.root[sam.dfsl[sam.nxt[temp][s[j+1] - 'a']]]-1,tree.root[sam.dfsr[sam.nxt[temp][s[j+1] - 'a']]],1,n,1,i)<<endl;
            temp = sam.nxt[temp][s[j+1] - 'a'];
            j++;
        }
        //cerr<<i<<" ->"<<j<<endl;
        while (!pq.empty() && pq.top().R < i)pq.pop();
        int dp_i = dp[i-1] + a;
        if (!pq.empty()){
            dp_i = min(dp_i,pq.top().dp_val);
        }
        dp[i] = dp_i;
        pq.push((Node){j,dp_i+b});
    }
    //for (int i=1;i<=n;i++){
    //    printf("dp[%d]=%d\n",i,dp[i]);
    //}
    printf("%d\n",dp[n]);
    //cout<<dp[n]<<endl;
    return 0;
}