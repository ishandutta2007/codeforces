//
// Created by calabash_boy on 18-6-4.
//SPOJ substring
// calc ans_i==i
//
//
// Created by calabash_boy on 18-10-18.
//
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+100;
char s[maxn];
int n;
int first[maxn],des[maxn*2],nxt[maxn*2],tot;
int a[maxn];
inline void addEdge(int x,int y){
    tot ++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //special
    int end_pos[maxn*2];
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');
            s++;
        }
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p]+1;
        last = np;
        while (p&&!nxt[p][c])nxt[p][c] = np,p = fa[p];
        if (!p)fa[np]=1;
        else{
            int q = nxt[p][c];
            if (l[q]==l[p]+1)fa[np] =q;
            else{
                int nq = ++ cnt;
                l[nq] = l[p]+1;
                memcpy(nxt[nq],nxt[q],sizeof (nxt[q]));
                fa[nq] =fa[q];
                fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
    void extract(char *s){
        a[1] = 0;
        for (int i=2;i<=cnt;i++){
            a[i] = l[i];
            addEdge(i,fa[i]);addEdge(fa[i],i);
        }
        int now = 1;
        for (int i=0;i<n;i++){
            now = nxt[now][s[i] - 'a'];
            end_pos[n-i] = now;
        }
    }
}sam;
int dep[maxn],fa[maxn];
int sz[maxn],wson[maxn];
int top[maxn],tpos[maxn],cnt;
int l[maxn],r[maxn],dfs_clock;
namespace Tree_Chain_Division{
    //depszwson
    void dfs(int node,int father){
        l[node] = ++dfs_clock;
        dep[node] = dep[father]+1;
        fa[node] = father;  sz[node] =1;
        for (int t = first[node];t;t = nxt[t]){
            int v = des[t];
            if (v==father){  continue;  }
            dfs(v,node);
            if (sz[v]>sz[wson[node]]){
                wson[node] = v;
            }
            sz[node]+=sz[v];
        }
        r[node] = dfs_clock;
    }
    //nodechain
    void dfs2(int node,int father,int chain){
        top[node] = chain;  tpos[node] = ++cnt;
        if (wson[node]){
            dfs2(wson[node],node,chain);
        }
        for (int t = first[node];t;t = nxt[t]){
            int v = des[t];
            if (v==father||v ==wson[node]){  continue;  }
            dfs2(v,node,v);
        }
    }
    /* s  */
    void init(int root){
        dfs(root,0);
        dfs2(root, 0, root);
    }
    int lca(int x,int y){
        while (top[x]!=top[y]){
            if (dep[top[x]]<dep[top[y]]){swap(x,y);}
            x = fa[top[x]];
        }
        if (dep[x]<dep[y])swap(x,y);
        return y;
    }
}
int color[maxn];
namespace Virtual_Tree{
    int vis[maxn];
    int dp[maxn][2];
    int top;
    int stk[maxn*2];
    int fa[maxn*2];
    long long solve(vector<int> node){
        long long ans =0;
        for (int i=0;i<node.size();i++) {
            vis[node[i]] = 1;
            dp[node[i]][0] = dp[node[i]][1] = 0;
        }
        auto cmp = [](int x,int y){return l[x]<l[y];};
        sort(node.begin(),node.end(),cmp);
        int sz = node.size();
        for (int i=1;i<sz;i++){
            int temp = Tree_Chain_Division::lca(node[i],node[i-1]);
            if (!vis[temp])vis[temp] = 2,node.push_back(temp),dp[temp][0] = dp[temp][1] = 0;
        }
        if (!vis[1])vis[1] = 2,node.push_back(1),dp[1][0] = dp[1][1] = 0;
        sort(node.begin(),node.end(),cmp);
        top = 1;
        stk[0] = node[0];
        for (int i=1;i<node.size();i++){
            while (l[node[i]] > r[stk[top-1]])top--;
            fa[node[i]] = stk[top-1];
            stk[top++] = node[i];
        }

        for (int i=(int)node.size()-1;i>=0;i--){
            int u = node[i];
            if (u == 1)continue;
            if (color[u]>=2){
                ans += 1ll * dp[u][0] * a[u];
                dp[u][1] ++;
                color[u]-=2;
            }
            if (color[u] >=1){
                ans += 1ll * dp[u][1] * a[u];
                dp[u][0] ++;
                color[u]-=1;
            }
            ans += 1ll * dp[fa[u]][0] * dp[u][1] * a[fa[u]];
            ans += 1ll * dp[fa[u]][1] * dp[u][0] * a[fa[u]];
            dp[fa[u]][0] += dp[u][0];
            dp[fa[u]][1] += dp[u][1];
        }
        for (int i=0;i<node.size();i++){
            int u = node[i];
            dp[u][0] = dp[u][1] = 0;
            color[u] = 0;
            vis[u] = 0;
            fa[u] = 0;
        }
        return ans;
    }
}
vector<int> node;
int N,M;
void solve(){
    node.clear();
    scanf("%d%d",&N,&M);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        temp = sam.end_pos[temp];
        color[temp] += 1;
        node.push_back(temp);;
    }
    for (int i=0;i<M;i++){
        int temp;
        scanf("%d",&temp);
        temp = sam.end_pos[temp];
        color[temp] += 2;
        node.push_back(temp);;
    }
    sort(node.begin(),node.end());
    node.erase(unique(node.begin(),node.end()),node.end());
    printf("%lld\n",Virtual_Tree::solve(node));
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    reverse(s,s+n);
    sam.clear();
    sam.init(s);
    sam.extract(s);
    Tree_Chain_Division::init(1);
    while (m--){
        solve();
    }
    return 0;
}