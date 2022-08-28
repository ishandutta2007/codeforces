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

char grid[200000][60];
int pos[60];
int dp[1 << 15];
int main() {
    int i,j;
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i][j]);
    }

    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    int t = 40,ans = 0;
    LLI mm = 0;
    while (t--) {
        int x = uniform_int_distribution<int>(0,n-1)(gen);
        int c = 0;
        vi v;
        for (i = 0; i < m; i++) {
            if (grid[x][i] == '1') pos[i] = c++,v.pb(i);
            else pos[i] = -1;
        }
        for (i = 0; i < (1 << c); i++) dp[i] = 0;
        for (i = 0; i < n; i++) {
            int b = 0;
            for (j = 0; j < v.size(); j++) {
                if (grid[i][v[j]] == '1') b |= (1 << j);
            }
            dp[b]++;
        }
        for (i = 0; i < c; i++) {
            for (j = 0; j < (1 << c); j++) {
                if (!(j & (1 << i))) dp[j] += dp[j|(1 << i)];
            }
        }
        int mmm = -1;
        for (i = 0; i < (1 << c); i++) {
            if (dp[i] >= (n+1)/2) {
                if (__builtin_popcount(i) > ans) {
                    ans = __builtin_popcount(i);
                    mmm = i;
                }
            }
        }
        if (mmm != -1) {
            mm = 0;
            for (i = 0; i < v.size(); i++) {
                if (mmm & (1 << i)) mm |= (1LL << v[i]);
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (mm & (1LL << i)) printf("1");
        else printf("0");
    }
    printf("\n");

    return 0;
}