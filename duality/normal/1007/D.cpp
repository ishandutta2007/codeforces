#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

int a[10000],b[10000],c[10000],d[10000];
vi adjList[100000];
int parent[100000],size[100000],depth[100000],heavy[100000];
int chain[100000],head[100000],disc[100000],csize[100000],num = 0,ch = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u] = p,size[u] = 1,depth[u] = d,heavy[u] = -1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            size[u] += doDFS(v,u,d+1);
            if ((heavy[u] == -1) || (size[v] > size[heavy[u]])) heavy[u] = v;
        }
    }
    return size[u];
}
int doHLD(int u,int p) {
    int i;
    chain[u] = ch,disc[u] = num++;
    if (csize[ch] == 0) head[ch] = u;
    csize[ch]++;
    if (heavy[u] != -1) doHLD(heavy[u],u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((v != p) && (v != heavy[u])) ch++,doHLD(v,u);
    }
    return 0;
}
vi tree[1 << 18];
int add(int s,int e,int as,int ae,int i,int u) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        tree[i].pb(u);
        return 0;
    }

    int mid = (s+e) / 2;
    add(s,mid,as,ae,2*i+1,u),add(mid+1,e,as,ae,2*i+2,u);
    return 0;
}
vi adjList2[5000000];
int process(int s,int e,int i,int u,int u2) {
    int j;
    for (j = 0; j < tree[i].size(); j++) {
        adjList2[tree[i][j]].pb(u);
        adjList2[num].pb(u),adjList2[num].pb(tree[i][j]^1);
        u = num++;
        adjList2[u2].pb(tree[i][j]^1);
        adjList2[u2].pb(num),adjList2[tree[i][j]].pb(num);
        u2 = num++;
    }
    if (s != e) {
        int mid = (s+e) / 2;
        process(s,mid,2*i+1,u,u2),process(mid+1,e,2*i+2,u,u2);
    }
    return 0;
}
int disc2[5000000],low[5000000],inStack[5000000],num2 = 0;
vi S;
int ans[10000];
int doDFS2(int u,int m) {
    int i;
    disc2[u] = low[u] = num2++;
    S.pb(u),inStack[u] = 1;
    for (i = 0; i < adjList2[u].size(); i++) {
        int v = adjList2[u][i];
        if (disc2[v] == -1) doDFS2(v,m),low[u] = min(low[u],low[v]);
        else if (inStack[v]) low[u] = min(low[u],disc2[v]);
    }
    if (disc2[u] == low[u]) {
        vi scc;
        while (1) {
            int v = S.back();
            S.pop_back(),inStack[v] = 0;
            scc.pb(v);
            if (u == v) break;
        }
        for (i = 0; i < scc.size(); i++) {
            if ((scc[i] < 2*m) && (ans[scc[i] >> 1] != 0)) break;
        }
        if (i == scc.size()) {
            for (i = 0; i < scc.size(); i++) {
                if (scc[i] < 2*m) {
                    if (ans[scc[i] >> 1] != 0) ans[scc[i] >> 1] = 0;
                    else ans[scc[i] >> 1] = (scc[i] & 1)+1;
                }
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n,m,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    scanf("%d",&m);
    for (i = 0; i < m; i++) scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]),a[i]--,b[i]--,c[i]--,d[i]--;

    doDFS(0,-1,0),doHLD(0,-1),ch++;
    for (i = 0; i < m; i++) {
        u = a[i],v = b[i];
        while (chain[u] != chain[v]) {
            if (depth[head[chain[u]]] < depth[head[chain[v]]]) swap(u,v);
            add(0,n-1,disc[head[chain[u]]],disc[u],0,2*i);
            u = parent[head[chain[u]]];
        }
        if (depth[u] > depth[v]) swap(u,v);
        add(0,n-1,disc[u]+1,disc[v],0,2*i);
        u = c[i],v = d[i];
        while (chain[u] != chain[v]) {
            if (depth[head[chain[u]]] < depth[head[chain[v]]]) swap(u,v);
            add(0,n-1,disc[head[chain[u]]],disc[u],0,2*i+1);
            u = parent[head[chain[u]]];
        }
        if (depth[u] > depth[v]) swap(u,v);
        add(0,n-1,disc[u]+1,disc[v],0,2*i+1);
    }
    num = 2*m+2;
    process(0,n-1,0,num-2,num-1);
    for (i = 0; i < num; i++) disc2[i] = low[i] = -1;
    for (i = 0; i < num; i++) {
        if (disc2[i] == -1) doDFS2(i,m);
    }
    for (i = 0; i < m; i++) {
        if (ans[i] == 0) break;
    }
    if (i < m) printf("NO\n");
    else {
        printf("YES\n");
        for (i = 0; i < m; i++) printf("%d\n",ans[i]);
    }

    return 0;
}