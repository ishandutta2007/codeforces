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
#define x first
#define y second

int x[300],y[300];
pii v[90000];
LLI cross(pii a,pii b) {
    return (LLI) a.x*b.y-(LLI) a.y*b.x;
}
int comp(pii a,pii b) {
    pii va = mp(x[a.second]-x[a.first],y[a.second]-y[a.first]);
    pii vb = mp(x[b.second]-x[b.first],y[b.second]-y[b.first]);
    int ha = (va.y > 0) || ((va.y == 0) && (va.x > 0));
    int hb = (vb.y > 0) || ((vb.y == 0) && (vb.x > 0));
    if (ha && !hb) return 1;
    else if (!ha & hb) return 0;
    else if (cross(va,vb) > 0) return 1;
    else return 0;
}
LLI dp[300][300][6];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&x[i],&y[i]);

    int j,k,c = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) v[c++] = mp(i,j);
        }
    }
    sort(v,v+c,comp);
    for (i = 0; i < n; i++) dp[i][i][0] = 1;
    for (i = 0; i < c; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < 5; k++) dp[j][v[i].second][k+1] += dp[j][v[i].first][k];
        }
    }
    LLI ans = 0;
    for (i = 0; i < n; i++) ans += dp[i][i][5];
    printf("%I64d\n",ans);

    return 0;
}