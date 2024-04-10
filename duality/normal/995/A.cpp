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

int a[4][50];
vector<pair<int,pii> > sol;
int main() {
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < n; j++) scanf("%d",&a[i][j]);
    }

    if (k == 2*n) {
        for (i = 1; i <= 2; i++) {
            for (j = 0; j < n; j++) {
                if ((a[i][j] != 0) && (a[i][j] == a[i^1][j])) {
                    sol.pb(mp(a[i][j],mp(i^1,j)));
                    a[i][j] = a[i^1][j] = 0;
                    k--;
                }
            }
        }
        if (sol.empty()) {
            printf("-1\n");
            return 0;
        }
    }

    vpii order;
    for (i = 0; i < n; i++) order.pb(mp(1,i));
    for (i = n-1; i >= 0; i--) order.pb(mp(2,i));
    while (k > 0) {
        for (i = 1; i <= 2; i++) {
            for (j = 0; j < n; j++) {
                if ((a[i][j] != 0) && (a[i][j] == a[i^1][j])) {
                    sol.pb(mp(a[i][j],mp(i^1,j)));
                    a[i][j] = a[i^1][j] = 0;
                    k--;
                }
            }
        }
        for (i = 0; i < order.size(); i++) {
            if (a[order[i].first][order[i].second] == 0) break;
        }
        int p = i;
        for (i = 1; i < order.size(); i++) {
            int u = (p+i) % order.size();
            int v = (p+i-1) % order.size();
            if (a[order[u].first][order[u].second] != 0) {
                sol.pb(mp(a[order[u].first][order[u].second],order[v]));
                a[order[v].first][order[v].second] = a[order[u].first][order[u].second];
                a[order[u].first][order[u].second] = 0;
            }
        }
    }
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d %d\n",sol[i].first,sol[i].second.first+1,sol[i].second.second+1);

    return 0;
}