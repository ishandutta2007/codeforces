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

int d[10000];
int dist[10000][1000];
deque<pii> Q;
int main() {
    int i;
    int n,m,g,r;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) scanf("%d",&d[i]);
    sort(d,d+m);
    scanf("%d %d",&g,&r);

    memset(dist,-1,sizeof(dist));
    dist[0][0] = 0,Q.pb(mp(0,0));
    while (!Q.empty()) {
        pii u = Q.front();
        Q.pop_front();

        int p = u.first,c = u.second;
        if (p > 0) {
            if (c+d[p]-d[p-1] <= g) {
                pii v = mp(p-1,c+d[p]-d[p-1]);
                if (v.second == g) {
                    v.second = 0;
                    if ((dist[v.first][v.second] == -1) || (dist[p][c]+1 < dist[v.first][v.second])) {
                        dist[v.first][v.second] = dist[p][c]+1;
                        Q.pb(v);
                    }
                }
                else if ((dist[v.first][v.second] == -1) || (dist[p][c] < dist[v.first][v.second])) {
                    dist[v.first][v.second] = dist[p][c];
                    Q.push_front(v);
                }
            }
        }
        if (p < m-1) {
            if (c+d[p+1]-d[p] <= g) {
                pii v = mp(p+1,c+d[p+1]-d[p]);
                if (v.second == g) {
                    v.second = 0;
                    if ((dist[v.first][v.second] == -1) || (dist[p][c]+1 < dist[v.first][v.second])) {
                        dist[v.first][v.second] = dist[p][c]+1;
                        Q.pb(v);
                    }
                }
                else if ((dist[v.first][v.second] == -1) || (dist[p][c] < dist[v.first][v.second])) {
                    dist[v.first][v.second] = dist[p][c];
                    Q.push_front(v);
                }
            }
        }
    }
    LLI ans = 1e18;
    for (i = 0; i < g; i++) {
        if ((i == 0) && (dist[m-1][i] != -1)) ans = min(ans,(LLI) (dist[m-1][i]-1)*(g+r)+g);
        else if ((i != 0) && (dist[m-1][i] != -1)) ans = min(ans,(LLI) dist[m-1][i]*(g+r)+i);
    }
    if (ans == 1e18) printf("-1\n");
    else printf("%I64d\n",ans);

    return 0;
}