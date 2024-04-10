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
int dp[100][1 << 4];
int main() {
    int i,j,k,l,p;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) scanf("%d",&a[i][j]),mm[j].first = max(mm[j].first,a[i][j]);
        }/*
        for (i = 0; i < m; i++) mm[i].second = i;
        sort(mm,mm+m,greater<pii>());
        int M = min(m,n+2);

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
        for (i = 0; i < masks.size(); i++) {
            dp[0][i] = 0;
            for (j = 0; j < n; j++) {
                int sum = 0;
                for (k = 0; k < n; k++) {
                    if (masks[i] & (1 << ((j+k) % n))) sum += a[k][mm[i].second];
                }
                dp[0][i] = max(dp[0][i],sum);
            }
        }
        for (i = 1; i < M; i++) {
            int c = mm[i].second;
            for (j = 0; j < masks.size(); j++) {
                for (k = masks[j]; k < (1 << n)-1; k = (k+1) | masks[j]) {

                }

            }

        }


        for (i = 0; i < )
        int c = 0;
        for (i = 0; i < masks.size(); i++) {
            for (j = 0; j < masks.size(); j++) {
                if ((masks[i] & masks[j]) == masks[i]) nxt[i].pb(j),c++;
            }
        }
        cout<<c<<endl;

        masks.clear();*/

        for (i = 0; i < (1 << n); i++) {
            dp[0][i] = 0;
            for (j = 0; j < n; j++) {
                if (i & (1 << j)) dp[0][i] += a[j][0];
            }
        }
        for (i = 1; i < m; i++) {
            for (j = 0; j < (1 << n); j++) dp[i][j] = 0;
            for (j = 0; j < (1 << n); j++) {
                for (k = 0; k < (1 << n); k++) {
                    if ((j & k) == j) {
                        int x = j ^ k;
                        int b = 0;
                        for (l = 0; l < n; l++) {
                            int sum = 0;
                            for (p = 0; p < n; p++) {
                                if (x & (1 << ((l+p) % n))) sum += a[p][i];
                            }
                            b = max(b,sum);
                        }
                        dp[i][k] = max(dp[i][k],dp[i-1][j]+b);
                    }
                }
            }
        }
        printf("%d\n",dp[m-1][(1 << n)-1]);
    }

    return 0;
}