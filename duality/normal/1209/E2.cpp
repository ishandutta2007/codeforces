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

int a[12][2000];
pii mm[2000];
vi masks;
int pos[1 << 12];
int best[12][1 << 12];
int dp[12][352];
int main() {
    int i,j,k,l,p;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) mm[i].first = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) scanf("%d",&a[i][j]),mm[j].first = max(mm[j].first,a[i][j]);
        }
        for (i = 0; i < m; i++) mm[i].second = i;
        sort(mm,mm+m,greater<pii>());
        int M = min(m,n);

        for (i = 0; i < (1 << n); i++) {
            int y;
            for (j = 0; j < n; j++) {
                int x = i & ((1 << j)-1);
                y = (i >> j) | (x << (n-j));
                if (y < i) break;
            }
            if (j == n) masks.pb(i),pos[i] = masks.size()-1;
            else pos[i] = pos[y];
        }
        printArr(masks,masks.size());
        debug "here";
        for (i = 0; i < M; i++) {
            for (j = 0; j < masks.size(); j++) {
                int x = masks[j],b = 0;
                for (k = 0; k < n; k++) {
                    int sum = 0;
                    for (l = 0; l < n; l++) {
                        if (x & (1 << ((k+l) % n))) sum += a[l][mm[i].second];
                    }
                    b = max(b,sum);
                }
                best[i][j] = b;
            }
            printArr(best[i],masks.size());
        }
        debug "here";
        for (i = 0; i < masks.size(); i++) dp[0][i] = best[0][i];
        printArr(dp[0],masks.size());
        debug "here";
        for (i = 1; i < M; i++) {
            for (j = 0; j < masks.size(); j++) dp[i][j] = 0;
            for (j = 0; j < masks.size(); j++) {
                for (k = masks[j]; k < (1 << n)-1; k = (k+1) | masks[j]) {
                    //debug k;
                    if ((masks[j] & k) == masks[j])
                        dp[i][pos[k]] = max(dp[i][pos[k]],dp[i-1][j]+best[i][pos[k^masks[j]]]);
                }
                if ((masks[j] & k) == masks[j])
                    dp[i][pos[k]] = max(dp[i][pos[k]],dp[i-1][j]+best[i][pos[k^masks[j]]]);
            }
        }
        int ans = 0;
        for (i = 0; i < masks.size(); i++) ans = max(ans,dp[M-1][i]);
        printf("%d\n",ans),masks.clear();
    }

    return 0;
}