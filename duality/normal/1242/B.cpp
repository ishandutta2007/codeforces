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
vi adjList2[100000];
int visited[100000];
int diff[100001];
int doDFS(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList2[u].size(); i++) doDFS(adjList2[u][i]);
    return 0;
}
int main() {
    int i,j;
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    for (i = 0; i < n; i++) {
        sort(adjList[i].begin(),adjList[i].end());
        if (!adjList[i].empty()) {
            if (adjList[i][0] > 0) {
                diff[0]++,diff[adjList[i][0]-1]--;
                adjList2[i].pb(0),adjList2[0].pb(i);
            }
            if (adjList[i].back() < n-1) {
                diff[adjList[i].back()+1]++,diff[n-1]--;
                adjList2[i].pb(n-1),adjList2[n-1].pb(i);
            }
        }
        else {
            adjList2[i].pb(0),adjList2[0].pb(i);
            diff[0]++,diff[n-1]--;
        }
        for (j = 1; j < adjList[i].size(); j++) {
            if (adjList[i][j-1]+1 < adjList[i][j]) {
                diff[adjList[i][j-1]+1]++;
                diff[adjList[i][j]-1]--;
                adjList2[i].pb(adjList[i][j-1]+1);
                adjList2[adjList[i][j-1]+1].pb(i);
            }
        }
    }
    for (i = 1; i < n; i++) diff[i] += diff[i-1];
    for (i = 0; i < n-1; i++) {
        if (diff[i] > 0) {
            adjList2[i].pb(i+1);
            adjList2[i+1].pb(i);
        }
    }
    int c = 0;
    for (i = 0; i < n; i++) {
        if (!visited[i]) doDFS(i),c++;
    }
    printf("%d\n",c-1);

    return 0;
}