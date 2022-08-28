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

vi adjList[200000],adjList2[200000];
int p[200000];
int dist[200000];
queue<int> Q;
set<pii> can,must;
int main() {
    int i;
    int n,m,k,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[v].pb(u);
        adjList2[u].pb(v);
    }
    scanf("%d",&k);
    for (i = 0; i < k; i++) scanf("%d",&p[i]),p[i]--;

    int j;
    fill(dist,dist+n,-1);
    dist[p[k-1]] = 0,Q.push(p[k-1]);
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            v = adjList[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
    for (i = 0; i < n; i++) {
        int c = 0;
        for (j = 0; j < adjList2[i].size(); j++) {
            v = adjList2[i][j];
            if (dist[i] == dist[v]+1) can.insert(mp(i,v)),c++;
        }
        if (c == 1) {
            for (j = 0; j < adjList2[i].size(); j++) {
                v = adjList2[i][j];
                if (dist[i] == dist[v]+1) must.insert(mp(i,v));
            }
        }
    }
    int s = 0,b = 0;
    for (i = 1; i < k; i++) {
        if (!can.count(mp(p[i-1],p[i]))) s++;
        if (!must.count(mp(p[i-1],p[i]))) b++;
    }
    printf("%d %d\n",s,b);

    return 0;
}