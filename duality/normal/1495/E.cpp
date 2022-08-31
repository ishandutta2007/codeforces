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

int p[200001],k[200001],b[200001],w[200001];
int seed = 0,base = 0;
int rnd() {
    int ret = seed;
    seed = ((LLI) seed*base + 233) % 1000000007;
    return ret;
}
int a[5000000],o[5000000],t[5000000];
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d %d",&p[i],&k[i],&b[i],&w[i]);
        seed = b[i],base = w[i];
        for (j = p[i-1]; j < p[i]; j++) {
            t[j] = (rnd() % 2) + 1;
            o[j] = a[j] = (rnd() % k[i]) + 1;
        }
    }

    LLI s1 = 0,s2 = 0;
    for (i = 0; i < n; i++) {
        if (t[i] == 1) s1 += a[i];
        else s2 += a[i];
    }
    if (s1 <= s2) {
        for (i = 0; i < n; i++) t[i] ^= 3;
    }
    if (t[0] == 1) a[0]--;
    LLI s = 0;
    for (i = 0; i < n; i++) {
        if (t[i] == 2) s += a[i],a[i] = 0;
        else {
            LLI x = min((LLI) a[i],s);
            a[i] -= x,s -= x;
        }
    }
    for (i = 0; i < n; i++) {
        if (t[i] == 2) s += a[i],a[i] = 0;
        else {
            LLI x = min((LLI) a[i],s);
            a[i] -= x,s -= x;
        }
    }
    LLI ans = 1;
    for (i = 0; i < n; i++) {
        ans *= (((o[i]-a[i])^((LLI) (i+1)*(i+1)))+1) % 1000000007;
        ans %= 1000000007;
    }
    printf("%I64d\n",ans);

    return 0;
}