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

LLI d[400001],num[400001];
plli v[400001];
int main() {
    int i;
    int t,m;
    LLI n,k,p,o;
    scanf("%d",&t);
    while (t--) {
        scanf("%I64d %d %I64d",&n,&m,&k),o = 0;
        for (i = 0; i < m; i++) scanf("%I64d",&p),d[i] = p-o,o = p;
        d[m++] = n-o,k += m;

        LLI l = 1,r = n;
        while (l < r) {
            LLI mid = (l+r) / 2;

            LLI c = 0;
            for (i = 0; i < m; i++) c += (d[i]+mid-1)/mid;
            if (c > k) l = mid+1;
            else r = mid;
        }
        LLI e = r;
        l = 1,r = *min_element(d,d+m);
        while (l < r) {
            LLI mid = (l+r+1) / 2;

            LLI c = 0;
            for (i = 0; i < m; i++) c += d[i]/mid;
            if (c < k) r = mid-1;
            else l = mid;
        }
        LLI s = l;
        int c = 0;
        for (i = 0; i < m; i++) {
            LLI a = d[i]/s;
            if ((d[i]+a-1)/a > e) v[c++] = mp((d[i]+a-1)/a-e,s-d[i]/(a+1));
        }
        if (c == 0) printf("%I64d\n",e-s);
        else {
            sort(v,v+c);
            LLI ans = e-s+v[c-1].first,ss = 0;
            for (i = c-1; i >= 0; i--) {
                ss = max(ss,v[i].second);
                ans = min(ans,e-s+((i == 0) ? 0:v[i-1].first)+ss);
            }
            printf("%I64d\n",ans);
        }
    }

    return 0;
}