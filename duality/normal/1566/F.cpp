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

LLI a[200002];
plli in[200002];
vplli vv;
LLI cost[200002][2][2],dp[200002][2];
int main() {
    int i;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n; i++) scanf("%I64d",&a[i]);
        for (i = 0; i < m; i++) scanf("%I64d %I64d",&in[i].first,&in[i].second);
        a[n++] = -1e10,a[n++] = 1e10;
        sort(a,a+n);
        sort(in,in+m);

        for (i = 0; i < m; i++) {
            while (!vv.empty() && (vv.back().second >= in[i].second)) vv.pop_back();
            vv.pb(in[i]);
        }
        sort(a,a+n);
        int j = 0;
        m = 0;
        for (i = 0; i < vv.size(); i++) {
            while ((j < n) && (a[j] < vv[i].first)) j++;
            if (a[j] > vv[i].second) in[m++] = vv[i];
        }
        vv.clear();
        if (m == 0) printf("0\n");
        else {
            LLI ans = 0;
            int j = 0,k;
            for (i = 0; i < n-1; i++) {
                while ((j < m) && (in[j].first < a[i])) j++;
                vplli v;
                while ((j < m) && (in[j].second < a[i+1])) {
                    v.pb(in[j]);
                    j++;
                }
                int x,y;
                for (x = 1; x <= 2; x++) {
                    for (y = 1; y <= 2; y++) {
                        LLI s = 1e18;
                        if (v.empty()) s = 0;
                        else {
                            s = min(s,x*(v.back().first-a[i]));
                            s = min(s,y*(a[i+1]-v[0].second));
                            for (k = 0; k < v.size()-1; k++) s = min(s,x*(v[k].first-a[i])+y*(a[i+1]-v[k+1].second));
                        }
                        cost[i][x-1][y-1] = s;
                    }
                }
            }
            dp[0][0] = dp[0][1] = 0;
            for (i = 1; i < n; i++) {
                dp[i][1] = min(dp[i-1][0]+cost[i-1][0][0],dp[i-1][1]+cost[i-1][1][0]);
                dp[i][0] = min(dp[i-1][0]+cost[i-1][0][1],dp[i-1][1]+cost[i-1][1][1]);
            }
            printf("%I64d\n",min(dp[n-1][0],dp[n-1][1]));
        }
    }

    return 0;
}