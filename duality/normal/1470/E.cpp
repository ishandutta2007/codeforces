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
#pragma GCC optimize("Ofast")

int p[30000];
LLI dp[30001][5];
LLI sub[30001][5][15];
vi order[30001][5];
int main() {
    int i,j,k;
    int t,n,c,q;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&c,&q);
        for (i = 0; i < n; i++) scanf("%d",&p[i]),p[i]--;

        memset(dp,0,sizeof(dp));
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= c; j++) order[i][j].clear();
        }
        for (i = 0; i <= c; i++) dp[n][i] = 1;
        for (i = n-1; i >= 0; i--) {
            for (j = 0; j <= c; j++) {
                vpii vv;
                for (k = 0; k <= j; k++) {
                    if (i+k >= n) break;
                    dp[i][j] += dp[i+k+1][j-k];
                    vv.pb(mp(p[i+k],k));
                }
                sort(vv.begin(),vv.end());
                order[i][j].resize(vv.size());
                for (k = 0; k < vv.size(); k++) order[i][j][k] = vv[k].second;
                sub[i][j][0] = 0;
                for (k = 0; k < vv.size(); k++) {
                    if (vv[k].second == 0) break;
                    else sub[i][j][0] += dp[i+order[i][j][k]+1][j-order[i][j][k]];
                }
            }
        }
        for (i = 1; i < 15; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k <= c; k++) {
                    if (j+(1 << i) < n) sub[j][k][i] = sub[j][k][i-1]+sub[j+(1 << (i-1))][k][i-1];
                }
            }
        }

        int a;
        LLI b;
        for (i = 0; i < q; i++) {
            scanf("%d %I64d",&a,&b),a--;
            if (b > dp[0][c]) {
                printf("-1\n");
                continue;
            }

            int u = 0,uc = c;
            vpii changed;
            while (u <= a) {
                for (j = 14; j >= 0; j--) {
                    if (u+(1 << j) >= n) continue;
                    if ((b > sub[u][uc][j]) && ((dp[u+(1 << j)][uc]+sub[u][uc][j]) >= b))
                        b -= sub[u][uc][j],u += (1 << j);
                }
                for (j = 0; j < order[u][uc].size(); j++) {
                    int v = order[u][uc][j];
                    if (b > dp[u+v+1][uc-v]) b -= dp[u+v+1][uc-v];
                    else {
                        if (v > 0) {
                            for (k = 0; k <= v; k++) changed.pb(mp(u+k,p[u+v-k]));
                        }
                        u += v+1,uc -= v;
                        break;
                    }
                }
            }
            for (j = 0; j < changed.size(); j++) {
                if (changed[j].first == a) {
                    printf("%d\n",changed[j].second+1);
                    break;
                }
            }
            if (j == changed.size()) printf("%d\n",p[a]+1);
        }
    }

    return 0;
}