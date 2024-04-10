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

vi adjList[100000];
int parent[100000],visited[100000];
vi cycle;
int f,del = -1;
int doDFS(int u) {
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v == del) continue;
        if (visited[v] == 0) parent[v] = u,doDFS(v);
        else if ((visited[v] == 1) && !f) {
            int w = u;
            while (w != v) cycle.pb(w),w = parent[w];
            cycle.pb(v);
            reverse(cycle.begin(),cycle.end()),f = 1;
        }
    }
    visited[u] = 2;
    return 0;
}
int pos[100000];
int far[100000],r;
int doDFS2(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1,far[u] = -1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (pos[v] == -1) {
            doDFS2(v);
            if (far[u] == -1) far[u] = far[v];
            else if ((far[v] != -1) && (far[u] != -1)) {
                if ((far[v] != -1) && (((pos[far[v]]-r-1+cycle.size()) % cycle.size()) \
                    > ((pos[far[u]]-r-1+cycle.size()) % cycle.size()))) far[u] = far[v];
            }
        }
        else {
            if (far[u] == -1) far[u] = v;
            else {
                if ((((pos[v]-r-1+cycle.size()) % cycle.size()) \
                    > ((pos[far[u]]-r-1+cycle.size()) % cycle.size()))) far[u] = v;
            }
        }
    }
    return 0;
}
int no[100001];
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
    }

    int j;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) doDFS(i);
    }
    fill(visited,visited+n,0);
    for (i = 0; i < n; i++) pos[i] = -1;
    for (i = 0; i < cycle.size(); i++) pos[cycle[i]] = i;
    for (i = 0; i < cycle.size(); i++) {
        for (j = 0; j < adjList[cycle[i]].size(); j++) {
            if (adjList[cycle[i]][j] == cycle[(i+1) % cycle.size()]) {
                swap(adjList[cycle[i]][j],adjList[cycle[i]].back());
                break;
            }
        }
        adjList[cycle[i]].pop_back();
    }
    for (i = 0; i < cycle.size(); i++) {
        r = i,doDFS2(cycle[i]);
        if (far[cycle[i]] != -1) {
            int p = pos[far[cycle[i]]];
            if (i < p) no[i+1]++,no[p]--;
            else no[i+1]++,no[0]++,no[p]--;
        }
    }
    for (i = 1; i < cycle.size(); i++) no[i] += no[i-1];
    for (i = 0; i < cycle.size(); i++) adjList[cycle[i]].pb(cycle[(i+1) % cycle.size()]);
    for (i = 0; i < cycle.size(); i++) {
        if (!no[i]) {
            del = cycle[i];
            break;
        }
    }
    fill(visited,visited+n,0),f = 0;
    for (i = 0; i < n; i++) {
        if ((i != del) && (visited[i] == 0)) doDFS(i);
    }
    if (f) printf("-1");
    else printf("%d\n",del+1);

    return 0;
}