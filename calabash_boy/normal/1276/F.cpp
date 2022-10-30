#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int n;
struct Suffix_Automaton{
    int nxt[maxn][26],fa[maxn],l[maxn];
    int last,cnt;
    vector<int> E[maxn];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    long long init(char *s){
        long long CNT = 0;
        while (*s){
            add(*s-'a');s++;
            CNT += l[last] - l[fa[last]];
        }
        for (int i=2;i<=cnt;i++)E[fa[i]].push_back(i);
        dfs(1);
        return CNT;
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
    int dfsl[maxn],dfsr[maxn],dfn;
    int sz[maxn],wson[maxn];
    void dfs(int u){
        dfsl[u] = ++dfn;
        sz[u] = 1;
        for (int v : E[u]){
            dfs(v);sz[u] += sz[v];
            if (sz[v] > sz[wson[u]])wson[u] = v;
        }
        dfsr[u] = dfn;
    }
};
struct SAM2:Suffix_Automaton{
    int fa[maxn];
    int top[maxn],dep[maxn];
    void dfs2(int u,int father,int chain){
        fa[u] = father;
        dep[u] = dep[fa[u]] + 1;
        top[u] = chain;
        if (wson[u])dfs2(wson[u],u,chain);
        for (int v : E[u]){
            if (v == wson[u])continue;
            dfs2(v,u,v);
        }
    }
    int lca(int x,int y){
        while (top[x]!=top[y]){
            if (dep[top[x]]<dep[top[y]]){swap(x,y);}
            x = fa[top[x]];
        }
        if (dep[x]<dep[y])swap(x,y);
        return y;
    }
    int pos[maxn];
    void work(char *t){
        int now = 1;
        for (int i = 1;i <=n;i++)pos[i] = now = nxt[now][t[i] - 'a'];
        dfs2(1,0,1);
    }
}sam2;
long long ans = 0;
struct cmp{
    bool operator()(const int& x, const int& y)const {
        return sam2.dfsl[sam2.pos[n  + 1 - x]] < sam2.dfsl[sam2.pos[n + 1 - y]];
    }
};
struct SAM1:Suffix_Automaton{
    set<int,cmp> R[maxn];
    long long count[maxn];
    int ed[maxn];
    void work(char *s){
        int now = 1;
        for (int i=1;i<=n;i++)ed[now = nxt[now][s[i] - 'a']] = i;
        work(1);
    }
    void insert(int target,int r){
        int *pos = sam2.pos;
        auto &st = R[target];
        int anc = 1;
        auto it = st.upper_bound(r);
        if (it != st.end()){
            int lca = sam2.lca(pos[n + 1 - r],pos[n + 1 - *it]);
            if (sam2.dep[lca] > sam2.dep[anc])anc = lca;
        }
        if (it != st.begin()){
            int lca = sam2.lca(pos[n + 1 - r],pos[n + 1 - *prev(it)]);
            if (sam2.dep[lca] > sam2.dep[anc])anc = lca;
        }
        count[target] += sam2.l[pos[n + 1 - r]] - sam2.l[anc];
        st.insert(r);
    }
    void work(int u){
        if (wson[u])work(wson[u]);
        swap(R[u],R[wson[u]]);
        swap(count[u],count[wson[u]]);
        for (int v : E[u]){
            if (v == wson[u])continue;
            work(v);
            for (int r : R[v])insert(u,r);
        }
        if (ed[u] >= 1 and ed[u] < n-1 or u == 1)insert(u,ed[u]+2);
        if (ed[u] != n)ans += 1ll * (l[u] - l[fa[u]]) *(count[u] + 1);
        if (u == 1)ans += (count[u] + 1);
    }
}sam;
char s[maxn],t[maxn];
int main(){
    cin>>s+1;
    n = strlen(s+1);
    ans = sam.init(s+1);
    strcpy(t+1,s+1);
    reverse(t + 1,t + 1 + n);
    sam2.init(t+1);
    sam2.work(t);
    sam.work(s);
    cout<<ans+1<<endl;
    return 0;
}