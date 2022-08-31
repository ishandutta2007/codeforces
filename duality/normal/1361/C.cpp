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

int a[500000],b[500000];
vpii adjList[1 << 20];
int visited[1 << 20];
int doDFS(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) doDFS(adjList[u][i].first);
    return 0;
}
int p[1 << 20];
vpii S,cycle;
int used[500000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&a[i],&b[i]);

    int j;
    for (i = 20; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            adjList[a[j] & ((1 << i)-1)].pb(mp(b[j] & ((1 << i)-1),j));
            adjList[b[j] & ((1 << i)-1)].pb(mp(a[j] & ((1 << i)-1),j));
        }
        for (j = 0; j < (1 << i); j++) {
            if (adjList[j].size() & 1) break;
        }
        if (j == (1 << i)) {
            int c = 0,u = 0;
            fill(visited,visited+(1 << i),0);
            for (j = 0; j < (1 << i); j++) {
                if (!adjList[j].empty() && !visited[j]) u = j,doDFS(j),c++;
            }
            if (c == 1) {
                S.pb(mp(u,-1));
                while (!S.empty()) {
                    int u = S.back().first;
                    while ((p[u] < adjList[u].size()) && used[adjList[u][p[u]].second]) p[u]++;
                    if (p[u] == adjList[u].size()) cycle.pb(S.back()),S.pop_back();
                    else {
                        S.pb(adjList[u][p[u]]);
                        used[adjList[u][p[u]].second] = 1,p[u]++;
                    }
                }
                printf("%d\n",i);
                for (j = 0; j < cycle.size()-1; j++) {
                    if ((a[cycle[j].second] & ((1 << i)-1)) == cycle[j].first) printf("%d %d ",2*cycle[j].second+1,2*cycle[j].second+2);
                    else printf("%d %d ",2*cycle[j].second+2,2*cycle[j].second+1);
                }
                printf("\n");
                break;
            }
        }
        for (j = 0; j < (1 << i); j++) adjList[j].clear();
    }

    return 0;
}