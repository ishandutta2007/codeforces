#define DEBUG 1

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

vi adjList[200000];
int a[200000],b[200000],uu[200000],vv[200000];
int parent[200000][18],best[200000][18],depth[200000];
int disc[200000],fin[200000],order[200000],num = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d;
    disc[u] = num++,order[num-1] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v,u,d+1);
    }
    fin[u] = num;
    return 0;
}
int logn;
int depth2[200000],root[200000];
int ans[200000],occ[200000];
struct event { int x,y1,y2,t,i; };
bool comp(event a,event b) {
    if (a.x == b.x) return a.t > b.t;
    return a.x < b.x;
}
vector<event> events;
int bit[200001];
int main() {
    int i;
    int n,m,q,p;
    scanf("%d",&n);
    for (i = 1; i < n; i++) scanf("%d",&p),adjList[p-1].pb(i);
    scanf("%d",&m);
    for (i = 0; i < m; i++) scanf("%d %d",&a[i],&b[i]),a[i]--,b[i]--;
    scanf("%d",&q);
    for (i = 0; i < q; i++) scanf("%d %d",&uu[i],&vv[i]),uu[i]--,vv[i]--;
    doDFS(0,-1,0);

    int j;
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    memset(best,-1,sizeof(best));
    for (i = 0; i < m; i++) {
        int u = a[i],v = b[i];
        if (depth[u] < depth[v]) swap(u,v);
        for (j = logn-1; j >= 0; j--) {
            if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[v])) u = parent[u][j];
        }
        if (u != v) {
            for (j = logn-1; j >= 0; j--) {
                if (parent[u][j] != parent[v][j]) u = parent[u][j],v = parent[v][j];
            }
            u = parent[u][0];
        }
        int lca = u;
        u = a[i],v = b[i];
        if (depth[u] < depth[v]) swap(u,v);
        for (j = logn-1; j >= 0; j--) {
            if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[v])) {
                if ((best[u][j] == -1) || (depth[lca] <= depth[best[u][j]])) best[u][j] = lca;
                u = parent[u][j];
            }
        }
        if (u != v) {
            for (j = logn-1; j >= 0; j--) {
                if (parent[u][j] != parent[v][j]) {
                    if ((best[u][j] == -1) || (depth[lca] <= depth[best[u][j]])) best[u][j] = lca;
                    if ((best[v][j] == -1) || (depth[lca] <= depth[best[v][j]])) best[v][j] = lca;
                    u = parent[u][j],v = parent[v][j];
                }
            }
            if ((best[u][0] == -1) || (depth[lca] <= depth[best[u][0]])) best[u][0] = lca;
            if ((best[v][0] == -1) || (depth[lca] <= depth[best[v][0]])) best[v][0] = lca;
        }
    }
    for (i = logn-1; i >= 1; i--) {
        for (j = 0; j < n; j++) {
            if (best[j][i] != -1) {
                if ((best[j][i-1] == -1) || (depth[best[j][i]] <= depth[best[j][i-1]])) best[j][i-1] = best[j][i];
                int u = parent[j][i-1];
                if ((best[u][i-1] == -1) || (depth[best[j][i]] <= depth[best[u][i-1]])) best[u][i-1] = best[j][i];
            }
        }
    }
    for (i = 1; i < logn; i++) {
        for (j = 0; j < n; j++) {
            if (best[j][i-1] != -1) best[j][i] = best[best[j][i-1]][i-1];
            else best[j][i] = -1;
        }
    }
    for (i = 0; i < n; i++) {
        int u = order[i];
        //cout<<u<<":"<<best[u][0]<<endl;
        if (best[u][0] == -1) depth2[u] = 0,root[u] = u;
        else depth2[u] = depth2[best[u][0]]+1,root[u] = root[best[u][0]];
    }

    for (i = 0; i < q; i++) {
        int u = uu[i],v = vv[i];
        if (root[u] != root[v]) {
            ans[i] = -1;
            continue;
        }
        if (depth[u] < depth[v]) swap(u,v);
        for (j = logn-1; j >= 0; j--) {
            if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[v])) u = parent[u][j];
        }
        if (u != v) {
            for (j = logn-1; j >= 0; j--) {
                if (parent[u][j] != parent[v][j]) u = parent[u][j],v = parent[v][j];
            }
            u = parent[u][0];
        }
        int lca = u;
        u = uu[i],v = vv[i];
        for (j = logn-1; j >= 0; j--) {
            if ((best[u][j] != -1) && (depth[best[u][j]] > depth[lca])) u = best[u][j];
        }
        for (j = logn-1; j >= 0; j--) {
            if ((best[v][j] != -1) && (depth[best[v][j]] > depth[lca])) v = best[v][j];
        }
        if (u != lca) u = best[u][0];
        if (v != lca) v = best[v][0];
        int x = depth2[uu[i]]-depth2[u],y = depth2[vv[i]]-depth2[v];
        ans[i] = x+y;
        if ((x > 0) && (y > 0)) {
            x--,y--;
            u = uu[i],v = vv[i];
            for (j = logn-1; j >= 0; j--) {
                if ((1 << j) <= x) u = best[u][j],x -= (1 << j);
            }
            for (j = logn-1; j >= 0; j--) {
                if ((1 << j) <= y) v = best[v][j],y -= (1 << j);
            }
            if (depth[u] > depth[v]) swap(u,v);
            //printVar(u);
            //printVar(v);
            if ((disc[v] >= disc[u]) && (disc[v] < fin[u])) {
                events.pb((event){disc[v],0,disc[u],1,i});
                events.pb((event){disc[v],fin[u],n-1,1,i});
                events.pb((event){fin[v]-1,0,disc[u],-1,i});
                events.pb((event){fin[v]-1,fin[u],n-1,-1,i});
            }
            else {
                events.pb((event){disc[u],disc[v],fin[v]-1,1,i});
                events.pb((event){fin[u]-1,disc[v],fin[v]-1,-1,i});
            }
        }
    }
    for (i = 0; i < m; i++) {
        events.pb((event){disc[a[i]],disc[b[i]],disc[b[i]],0,-1});
        events.pb((event){disc[b[i]],disc[a[i]],disc[a[i]],0,-1});
        //cout<<"point "<<disc[a[i]]<<","<<disc[b[i]]<<endl;
    }
    sort(events.begin(),events.end(),comp);
    for (i = 0; i < events.size(); i++) {
        //cout<<events[i].x<<","<<events[i].y1<<","<<events[i].y2<<","<<events[i].t<<","<<events[i].i<<endl;
        if (events[i].t == 0) {
            for (j = events[i].y1+1; j <= n; j += j & (-j)) bit[j]++;
        }
        else {
            for (j = events[i].y2+1; j > 0; j -= j & (-j)) occ[events[i].i] -= events[i].t*bit[j];
            for (j = events[i].y1; j > 0; j -= j & (-j)) occ[events[i].i] += events[i].t*bit[j];
        }
    }
    for (i = 0; i < q; i++) {
        if (occ[i] > 0) ans[i]--;
        printf("%d\n",ans[i]);
    }

    return 0;
}