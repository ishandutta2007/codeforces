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

LLI a[20];
int poss[1 << 20],dp[1 << 20];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d",&a[i]);

    int j,k;
    vi pp;
    for (i = 1; i < (1 << n); i++) {
        vi v;
        LLI sum = 0;
        int c = 0;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) v.pb(j),sum += a[j],c += (a[j] != 0);
        }
        if ((v.size() >= 2) && ((sum+v.size()) & 1)) {
            int h = v.size()/2;
            vector<pair<LLI,int> > vv;
            for (j = 0; j < (1 << h); j++) {
                LLI d = 0;
                for (k = 0; k < h; k++) {
                    if (j & (1 << k)) d += a[v[k]];
                    else d -= a[v[k]];
                }
                vv.pb(mp(d,j));
            }
            sort(vv.begin(),vv.end());
            for (j = 0; j < (1 << (v.size()-h)); j++) {
                LLI d = 0;
                for (k = 0; k < v.size()-h; k++) {
                    if (j & (1 << k)) d += a[v[k+h]];
                    else d -= a[v[k+h]];
                }
                int p = lower_bound(vv.begin(),vv.end(),mp(-d,0))-vv.begin();
                if ((p < vv.size()) && (vv[p].first+d <= v.size()-1)) {
                    int m = vv[p].second | (j << h);
                    if ((m == 0) || (m == (1 << v.size())-1)) {
                        p++;
                        if ((p >= vv.size()) || (vv[p].first+d > v.size()-1)) continue;
                    }
                    poss[i] = 1;
                    break;
                }
            }
        }
        dp[i] = c;
        if (poss[i]) dp[i] = min(dp[i],(int) v.size()-1);
        if ((1 << (v.size()-1)) < pp.size()) {
            for (j = i^(1 << v.back()); j > 0; j = (j-1) & i) dp[i] = min(dp[i],dp[i^j]+dp[j]);
        }
        else {
            for (j = 0; j < pp.size(); j++) {
                if ((pp[j] & i) == pp[j]) dp[i] = min(dp[i],dp[i^pp[j]]+dp[pp[j]]);
            }
        }
        if (poss[i] && (dp[i] == v.size()-1)) pp.pb(i);
    }
    printf("%d\n",dp[(1 << n)-1]);

    return 0;
}