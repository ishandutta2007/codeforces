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

int c[200][200];
LLI pre[201][201];
LLI dp[200][200];
int best[200][200];
LLI query(int l,int r,int d,int u) {
    if ((l > r) || (d > u)) return 0;
    return pre[r+1][u+1]-pre[l][u+1]-pre[r+1][d]+pre[l][d];
}
int t[200];
int getAns(int l,int r,int p) {
    if (l == r) {
        t[l] = p;
        return 0;
    }

    int m = best[l][r];
    t[m] = p;
    if (l < m) getAns(l,m-1,m);
    if (m < r) getAns(m+1,r,m);
    return 0;
}
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&c[i][j]),pre[i+1][j+1] = pre[i+1][j]+pre[i][j+1]-pre[i][j]+c[i][j];
    }

    int k;
    for (i = n-1; i >= 0; i--) {
        for (j = i+1; j < n; j++) {
            dp[i][j] = 1e18;
            for (k = i; k <= j; k++) {
                LLI x = ((i == k) ? 0:dp[i][k-1])+((k == j) ? 0:dp[k+1][j]);
                x += query(i,k-1,0,i-1)+query(i,k-1,k,n-1);
                x += query(k+1,j,0,k)+query(k+1,j,j+1,n-1);
                if (x < dp[i][j]) dp[i][j] = x,best[i][j] = k;
            }
        }
    }
    getAns(0,n-1,-1);
    for (i = 0; i < n; i++) printf("%d ",t[i]+1);
    printf("\n");

    return 0;
}