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
#define MOD 1000000007

vi adjList[500000];
int a[500000];
int parent[500000][19],depth[500000],disc[500000],fin[500000],num = 0;
int up[500000][19],down[500000][19];
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    fin[u] = num;
    return 0;
}
int first[500000],last[500000],out[500000],in[500000];
vpii edges[500000];
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--;
    for (i = 0; i < n; i++) {
        if (a[i] == i) {
            printf("0\n");
            return 0;
        }
    }

    int j;
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    int logn = i;
    for (i = 0; i < n; i++) first[i] = last[i] = -1;
    for (i = 0; i < n; i++) {
        if (a[i] != -1) {
            int u = a[i],v = i;
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
            int l = u;
            if (l == a[i]) {
                for (j = 0; j < adjList[a[i]].size(); j++) {
                    v = adjList[a[i]][j];
                    if ((v != parent[a[i]][0]) && (disc[i] >= disc[v]) && (disc[i] < fin[v])) break;
                }
                first[a[i]] = v,last[i] = parent[i][0];
                v = i;
                for (j = logn-1; j >= 0; j--) {
                    if ((parent[v][j] != -1) && (depth[parent[v][j]] >= depth[l]+2)) down[v][j] = 1,v = parent[v][j];
                }
                if (depth[v] >= depth[l]+2) down[v][0] = 1,v = parent[v][0];
            }
            else if (l == i) {
                for (j = 0; j < adjList[i].size(); j++) {
                    v = adjList[i][j];
                    if ((v != parent[i][0]) && (disc[a[i]] >= disc[v]) && (disc[a[i]] < fin[v])) break;
                }
                first[a[i]] = parent[a[i]][0],last[i] = v;
                u = a[i];
                for (j = logn-1; j >= 0; j--) {
                    if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[l]+2)) up[u][j] = 1,u = parent[u][j];
                }
                if (depth[u] >= depth[l]+2) up[u][0] = 1,u = parent[u][0];
            }
            else {
                first[a[i]] = parent[a[i]][0],last[i] = parent[i][0];
                u = a[i];
                for (j = logn-1; j >= 0; j--) {
                    if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[l]+2)) up[u][j] = 1,u = parent[u][j];
                }
                if (depth[u] >= depth[l]+2) up[u][0] = 1,u = parent[u][0];
                v = i;
                for (j = logn-1; j >= 0; j--) {
                    if ((parent[v][j] != -1) && (depth[parent[v][j]] >= depth[l]+2)) down[v][j] = 1,v = parent[v][j];
                }
                if (depth[v] >= depth[l]+2) down[v][0] = 1,v = parent[v][0];
                edges[parent[u][0]].pb(mp(u,v));
            }
        }
    }
    for (i = logn-1; i > 0; i--) {
        for (j = 0; j < n; j++) {
            if (up[j][i]) up[j][i-1] = up[parent[j][i-1]][i-1] = 1;
            if (down[j][i]) down[j][i-1] = down[parent[j][i-1]][i-1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (up[i][0]) edges[parent[i][0]].pb(mp(i,parent[i][1]));
        if (down[i][0]) edges[parent[i][0]].pb(mp(parent[i][1],i));
    }
    int ways = 1;
    for (i = 0; i < n; i++) {
        int e = 0;
        for (j = 0; j < adjList[i].size(); j++) in[adjList[i][j]] = out[adjList[i][j]] = -1;
        for (j = 0; j < edges[i].size(); j++) {
            if (out[edges[i][j].first] != -1) {
                if (edges[i][j].second != out[edges[i][j].first]) {
                    printf("0\n");
                    return 0;
                }
            }
            else out[edges[i][j].first] = edges[i][j].second,e++;
            if (in[edges[i][j].second] != -1) {
                if (edges[i][j].first != in[edges[i][j].second]) {
                    printf("0\n");
                    return 0;
                }
            }
            else in[edges[i][j].second] = edges[i][j].first;
        }
        int x = adjList[i].size()-e;
        if ((first[i] != -1) && (in[first[i]] != -1)) {
            printf("0\n");
            return 0;
        }
        if ((last[i] != -1) && (out[last[i]] != -1)) {
            printf("0\n");
            return 0;
        }
        for (j = 0; j < adjList[i].size(); j++) {
            if (in[adjList[i][j]] == -1) {
                int u = adjList[i][j];
                while (out[u] != -1) u = out[u],e--;
            }
        }
        if (e != 0) {
            printf("0\n");
            return 0;
        }
        if ((first[i] == -1) && (last[i] == -1)) {
            for (j = 1; j <= x; j++) ways = ((LLI) ways*j) % MOD;
        }
        else if ((first[i] == -1) || (last[i] == -1)) {
            for (j = 1; j <= x-1; j++) ways = ((LLI) ways*j) % MOD;
        }
        else {
            int u = first[i];
            while (out[u] != -1) u = out[u];
            if (u == last[i]) {
                if (x > 1) {
                    printf("0\n");
                    return 0;
                }
            }
            else {
                for (j = 1; j <= x-2; j++) ways = ((LLI) ways*j) % MOD;
            }
        }
    }
    printf("%d\n",ways);

    return 0;
}