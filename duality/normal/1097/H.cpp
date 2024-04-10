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

int d,m;
int gen[20];
vlli B;
LLI dp[100][60];
LLI shift(LLI b,int x) {
    return (b >> x) | ((b & ((1LL << x)-1)) << (m-x));
}
map<LLI,int> M;
int num = 0;
LLI ans[100][60];
int xx[100][60];
LLI solve(vlli v,LLI r,int s) {
    if (r == 0) return 0;
    else if (v.size() == 1) {
        int i = 0;
        if (r == 1) return (v[0] & 1) ? 1:0;
        if (!M.count(r)) {
            int j,k,c = 0,digits[100];
            LLI x = r-1;
            while (x > 0) digits[i++] = x % d,x /= d;
            for (i--; i >= 0; i--) {
                for (j = 0; j < digits[i]; j++) {
                    for (k = 0; k < m; k++) ans[num][k] += dp[i][(((k-c-gen[j]) % m)+m) % m];
                }
                if (i == 0) {
                    for (k = 0; k < m; k++) ans[num][k] += dp[i][(((k-c-gen[j]) % m)+m) % m];
                }
                c += gen[j],c %= m;
            }
            M[r] = num++;
        }
        int p = M[r];
        for (i = 0; i < m; i++) {
            if (v[0] & (1LL << i)) xx[p][i] += s;
        }
        return 0;
    }

    int i,j;
    LLI ans = 0;
    for (i = 0; i < v.size(); i++) {
        if (v[i] == 0) return 0;
    }
    for (i = 0; i < d; i++) {
        vlli v2((i+v.size()-1)/d+1,(1LL << m)-1);
        for (j = 0; j < v.size(); j++) v2[(j+i)/d] &= shift(v[j],gen[(i+j) % d]);
        ans += solve(v2,(r-i+d-1)/d,s);
    }
    return ans;
}
int main() {
    int i;
    int n;
    LLI l,r;
    scanf("%d %d",&d,&m);
    for (i = 0; i < d; i++) scanf("%d",&gen[i]);
    scanf("%d",&n),B.resize(n);
    for (i = 0; i < n; i++) scanf("%I64d",&B[i]),B[i] = (1LL << (B[i]+1))-1;
    scanf("%I64d %I64d",&l,&r);

    int j,k;
    dp[0][0] = 1;
    for (i = 1; i < 100; i++) {
        if (pow(d,i) > 3e18) break;
        for (j = 0; j < m; j++) {
            for (k = 0; k < d; k++) dp[i][j] += dp[i-1][(j-gen[k]+m) % m];
        }
    }
    LLI sum = solve(B,r-n+1,1)-solve(B,l-1,-1);
    for (i = 0; i < num; i++) {
        for (j = 0; j < m; j++) sum += xx[i][j]*ans[i][j];
    }
    printf("%I64d\n",sum);

    return 0;
}