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

vpii adjList[600];
int dist[600];
vi Q[605];
int main() {
    int i;
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&a,&b,&c);
        adjList[a].pb(mp(b,c));
    }

    int j,k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) dist[j] = 1e9+1000;
        dist[i] = 0;
        for (j = 0; j < adjList[i].size(); j++) {
            for (k = 0; k < n; k++) dist[(adjList[i][j].first+k) % n] = min(dist[(adjList[i][j].first+k) % n],adjList[i][j].second+k);
        }
        int s = 1e9+1000;
        for (j = 0; j < n; j++) {
            if (i != j) s = min(s,dist[j]);
        }
        for (j = 0; j < n; j++) {
            if (i != j) Q[dist[j]-s].pb(j);
        }
        int p = 0;
        while (p < n+5) {
            while (!Q[p].empty()) {
                int u = Q[p].back();
                Q[p].pop_back();

                if (p+s > dist[u]) continue;
                for (j = 0; j < adjList[u].size(); j++) {
                    int v = (adjList[u][j].first+dist[u]) % n;
                    if (dist[u]+adjList[u][j].second < dist[v]) {
                        dist[v] = dist[u]+adjList[u][j].second;
                        Q[dist[v]-s].pb(v);
                    }
                    if (v == i) {
                        int t = v;
                        for (k = 0; k < n; k++) {
                            v = (t+k) % n;
                            if (dist[u]+adjList[u][j].second+k < dist[v]) {
                                dist[v] = dist[u]+adjList[u][j].second+k;
                                Q[dist[v]-s].pb(v);
                            }
                        }
                    }
                }
                for (j = 0; j < n; j++) {
                    int v = (u+j) % n;
                    if (dist[u]+j < dist[v]) {
                        dist[v] = dist[u]+j;
                        Q[dist[v]-s].pb(v);
                    }
                }
            }
            p++;
        }
        for (j = 0; j < n; j++) printf("%d ",dist[j]);
        printf("\n");
    }

    return 0;
}