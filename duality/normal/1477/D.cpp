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

vi adjList[500000],adjList2[500000],adjList3[500000];
int visited[500000];
vi vv;
int ansp[500000],ansq[500000];
int doDFS(int u) {
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList2[u].size(); i++) {
        int v = adjList2[u][i];
        if (!visited[v]) adjList3[u].pb(v),adjList3[v].pb(u),doDFS(v);
    }
    return 0;
}
int deg[500000];
queue<int> Q;
int main() {
    int i;
    int t,n,m,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        int j,c = n-1;
        fill(visited,visited+n,0);
        for (i = 0; i < n; i++) sort(adjList[i].begin(),adjList[i].end());
        for (i = 0; i < n; i++) {
            if (adjList[i].size() == n-1) {
                ansp[i] = ansq[i] = c--;
                visited[i] = 1;
            }
            else vv.pb(i);
        }
        for (i = 0; i < n; i++) {
            if (!visited[i] && adjList2[i].empty()) {
                int k = 0;
                for (j = 0; j < vv.size(); j++) {
                    while ((k < adjList[i].size()) && (adjList[i][k] < vv[j])) k++;
                    if ((k == adjList[i].size()) || (adjList[i][k] != vv[j])) {
                        if (vv[j] != i) {
                            adjList2[i].pb(vv[j]);
                            adjList2[vv[j]].pb(i);
                            break;
                        }
                    }
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (!visited[i]) doDFS(i);
        }
        for (i = 0; i < n; i++) {
            deg[i] = adjList3[i].size();
            if (adjList3[i].size() == 1) Q.push(i);
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            if (deg[u] != 1) continue;

            for (i = 0; i < adjList3[u].size(); i++) {
                int v = adjList3[u][i];
                if (deg[v] > 0) break;
            }
            int uu = adjList3[u][i];
            deg[uu] = 0;
            vi x;
            for (i = 0; i < adjList3[uu].size(); i++) {
                int v = adjList3[uu][i];
                if (deg[v] > 0) {
                    deg[v]--;
                    if (deg[v] == 1) Q.push(v);
                    else if (deg[v] == 0) x.pb(v);
                }
            }
            ansp[uu] = c,ansq[uu] = c-x.size();
            for (i = 0; i < x.size(); i++) ansp[x[i]] = c-i-1,ansq[x[i]] = c-i;
            c -= x.size()+1;
        }
        for (i = 0; i < n; i++) printf("%d ",ansp[i]+1);
        printf("\n");
        for (i = 0; i < n; i++) printf("%d ",ansq[i]+1);
        printf("\n");

        for (i = 0; i < n; i++) adjList[i].clear(),adjList2[i].clear(),adjList3[i].clear();
        vv.clear();
    }

    return 0;
}