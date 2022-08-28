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
#define MOD 1000000007

int n,a[1000000];
int sparse[20][1000000],logg[1000001];
int query(int l,int r) {
    if (r >= n) return 1e9;
    int x = logg[r-l+1];
    return max(sparse[x][l],sparse[x][r-(1 << x)+1]);
}
vpii v[1000000];
LLI sum[1000000];
LLI query2(int p,int x,int x2) {
    int num = 1;
    while (!v[p].empty() && (v[p].back().first <= x)) {
        num += v[p].back().second;
        sum[p] -= (LLI) v[p].back().first*v[p].back().second;
        v[p].pop_back();
    }
    v[p].pb(mp(x,num)),sum[p] += (LLI) x*num;
    LLI r = sum[p];
    x = x2;
    num = 0;
    while (!v[p].empty() && (v[p].back().first <= x)) {
        num += v[p].back().second;
        sum[p] -= (LLI) v[p].back().first*v[p].back().second;
        v[p].pop_back();
    }
    v[p].pb(mp(x,num)),sum[p] += (LLI) x*num;
    return r;
}
int main() {
    int i;
    int k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),sparse[0][i] = a[i];

    int j;
    LLI ans = 0;
    for (i = 1; (1 << i) <= n; i++) {
        for (j = 0; j <= n-(1 << i); j++) sparse[i][j] = max(sparse[i-1][j],sparse[i-1][j+(1 << (i-1))]);
    }
    for (i = 2; i <= n; i++) logg[i] = logg[i/2]+1;
    for (i = 0; i < n; i++) {
        ans += MOD-a[i]+query2(i % (k-1),a[i],query(i,i+k-2));
        ans %= MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}