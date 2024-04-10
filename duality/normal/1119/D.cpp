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

LLI s[100000];
vlli t;
vector<pair<LLI,plli> > v;
vlli ans;
int main() {
    int i;
    int n,q;
    LLI l,r;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d",&s[i]);
    sort(s,s+n);
    for (i = 0; i < n-1; i++) t.pb(s[i+1]-s[i]);
    sort(t.begin(),t.end());
    LLI num = 0,c = n;
    v.pb(mp(0,mp(0,n)));
    for (i = 0; i < t.size(); i++) {
        LLI x = (i == 0) ? t[i]:(t[i]-t[i-1]);
        num += x*c,c--;
        v.pb(mp(t[i],mp(num,c)));
    }
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%I64d %I64d",&l,&r);
        r -= l,r++;
        int p = upper_bound(v.begin(),v.end(),mp(r,mp((LLI) 2e18,(LLI) 2e18)))-v.begin()-1;
        ans.pb(v[p].second.first+(r-v[p].first)*v[p].second.second);
    }
    for (i = 0; i < q; i++) printf("%I64d ",ans[i]);
    printf("\n");

    return 0;
}