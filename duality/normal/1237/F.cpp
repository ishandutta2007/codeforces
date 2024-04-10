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
#define MOD 998244353

int r[3600],c[3600];
vi a,b;
LLI C[3601][3601],fact[3601];
LLI dpa[3601][1801],dpb[3601][1801];
int main() {
    int i,j;
    int h,w,n;
    int r1,c1,r2,c2;
    scanf("%d %d %d",&h,&w,&n);
    fill(r,r+h,1),fill(c,c+w,1);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        r1--,c1--,r2--,c2--;
        r[r1] = r[r2] = 0,c[c1] = c[c2] = 0;
    }

    for (i = 0; i < h; i++) {
        if (r[i]) {
            if ((i == h-1) || !r[i+1]) a.pb(1);
            else a.pb(0);
        }
    }
    for (i = 0; i < w; i++) {
        if (c[i]) {
            if ((i == w-1) || !c[i+1]) b.pb(1);
            else b.pb(0);
        }
    }
    dpa[0][0] = 1;
    for (i = 0; i < a.size(); i++) {
        for (j = 0; j <= a.size()/2; j++) {
            dpa[i+1][j] = dpa[i][j];
            if ((i > 0) && !a[i-1] && (j > 0)) dpa[i+1][j] += dpa[i-1][j-1];
            dpa[i+1][j] %= MOD;
        }
    }
    dpb[0][0] = 1;
    for (i = 0; i < b.size(); i++) {
        for (j = 0; j <= b.size()/2; j++) {
            dpb[i+1][j] = dpb[i][j];
            if ((i > 0) && !b[i-1] && (j > 0)) dpb[i+1][j] += dpb[i-1][j-1];
            dpb[i+1][j] %= MOD;
        }
    }
    LLI ans = 0;
    C[0][0] = 1;
    for (i = 1; i <= max(a.size(),b.size()); i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j]+C[i-1][j-1]) % MOD;
    }
    fact[0] = 1;
    for (i = 1; i <= max(a.size(),b.size()); i++) fact[i] = (i*fact[i-1]) % MOD;
    for (i = 0; i <= a.size()/2; i++) {
        for (j = 0; j <= b.size()/2; j++) {
            LLI c = ((LLI) dpa[a.size()][i]*dpb[b.size()][j]) % MOD;
            LLI d = ((LLI) C[a.size()-2*i][j]*C[b.size()-2*j][i]) % MOD;
            LLI e = ((LLI) fact[i]*fact[j]) % MOD;
            ans += ((c*d) % MOD)*e,ans %= MOD;
        }
    }
    printf("%d\n",(int) ans);

    return 0;
}