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

int x[200000],y[200000],s[200000];
pii order[400000];
int num[400001];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d %d",&x[i],&y[i],&s[i]);
    
    for (i = 0; i < n; i++) order[i] = mp(x[i],i),order[i+n] = mp(y[i],i);
    sort(order,order+2*n);
    num[2*n] = 1;
    for (i = 2*n-1; i >= 0; i--) {
        if (x[order[i].second] == order[i].first) {
            if (s[order[i].second] == 1) num[i] = 2*num[i+1];
            else num[i] = 2*num[i+1]-1;
            num[i] %= MOD;
            if (num[i] < 0) num[i] += MOD;
        }
        else {
            int p = lower_bound(order,order+2*n,mp(x[order[i].second],0))-order;
            num[i] = (num[i+1]-num[p+1]+(s[order[i].second] == 0)+MOD) % MOD;
        }
    }
    LLI ans = 1;
    for (i = 0; i < 2*n; i++) {
        ans += (LLI) num[i]*(order[i].first-((i == 0) ? 0:order[i-1].first));
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}