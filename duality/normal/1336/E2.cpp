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
#define MOD 998244353

LLI basis[53],occ[53];
vlli v,v2;
int ways[54];
int doDFS(int c,LLI x) {
    if (c == v.size()) {
        ways[__builtin_popcountll(x)]++;
        return 0;
    }

    doDFS(c+1,x),doDFS(c+1,x^v[c]);
    return 0;
}
int C[54][54],num[54];
int doDFS2(int c,LLI x,int y) {
    if (c == v2.size()) {
        num[__builtin_popcountll(x)+y]++;
        return 0;
    }

    doDFS2(c+1,x,y),doDFS2(c+1,x^v2[c],y+1);
    return 0;
}
int main() {
    int i,j;
    int n,m,c = 0;
    LLI a;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        scanf("%I64d",&a);
        for (j = 0; j < m; j++) {
            if (a & (1LL << j)) {
                if (basis[j] == 0) {
                    basis[j] = a,c++;
                    break;
                }
                else a ^= basis[j];
            }
        }
    }

    int p = 1;
    for (i = 0; i < n-c; i++) p = (2*p) % MOD;
    if (c <= m/2) {
        for (i = 0; i < m; i++) {
            if (basis[i] != 0) v.pb(basis[i]);
        }
        doDFS(0,0);
    }
    else {
        for (i = 0; i <= m; i++) {
            C[i][0] = 1;
            for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
        }
        c = 0;
        for (i = 0; i < m; i++) {
            if (basis[i] != 0) {
                for (j = i+1; j < m; j++) {
                    if ((basis[j] != 0) && (basis[i] & (1LL << j))) basis[i] ^= basis[j];
                }
                for (j = 0; j < m; j++) {
                    if ((basis[j] == 0) && (basis[i] & (1LL << j))) occ[j] ^= (1LL << c);
                }
                c++;
            }
        }
        for (i = 0; i < m; i++) {
            if (basis[i] == 0) v2.pb(occ[i]);
        }
        doDFS2(0,0,0);
        int k;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= i; j++) {
                for (k = 0; k <= m-i; k++) {
                    if (j & 1) ways[j+k] += MOD-(((((LLI) num[i]*C[i][j]) % MOD)*C[m-i][k]) % MOD);
                    else ways[j+k] += ((((LLI) num[i]*C[i][j]) % MOD)*C[m-i][k]) % MOD;
                    ways[j+k] %= MOD;
                }
            }
        }
        for (i = 0; i < m-c; i++) p = ((LLI) p*((MOD+1)/2)) % MOD;
    }
    for (i = 0; i <= m; i++) {
        ways[i] = ((LLI) ways[i]*p) % MOD;
        printf("%d ",ways[i]);
    }
    printf("\n");

    return 0;
}