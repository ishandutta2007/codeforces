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

int c[500000];
LLI sum[500001];
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&c[i]);
    sort(c,c+n);

    vi pos,neg;
    for (i = 0; i < n; i++) {
        if (c[i] >= 0) pos.pb(c[i]);
        else neg.pb(c[i]);
    }
    if (neg.empty()) {
        LLI ans = 0;
        for (i = 0; i < pos.size(); i++) ans += (LLI) i*pos[i];
        printf("%I64d\n",ans);
        return 0;
    }
    for (i = 0; i < neg.size(); i++) sum[(neg.size()-1)/(k+1)] += (LLI) neg[i]*(i/(k+1));
    LLI s = 0,s2 = 0,s3 = 0,ans = -9e18;
    for (i = 0; i < pos.size(); i++) s3 += (LLI) i*pos[i],s2 += pos[i];
    int c = (neg.size()-1)/(k+1);
    for (i = neg.size()-1; i >= 0; i--) {
        s += neg[i];
        if ((i % (k+1)) != 0) sum[c+1] = sum[c]+s,c++;
    }
    for (i = (neg.size()-1)/(k+1); i <= c; i++) ans = max(ans,sum[i]+(i+1)*s2+s3);
    printf("%I64d\n",ans);

    return 0;
}