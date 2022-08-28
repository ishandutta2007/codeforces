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

int a[200000],b[200000];
vector<pair<LLI,int> > vv;
int main() {
    int i;
    int n;
    LLI k;
    scanf("%d %I64d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    LLI l = -4e18,r = 1e10;
    while (l < r) {
        LLI m = l+(r-l)/2;

        LLI c = 0;
        for (i = 0; i < n; i++) {
            int ll = -1,rr = a[i]-1;
            while (ll < rr) {
                int mm = (ll+rr+1) / 2;
                if (3LL*mm*mm+3LL*mm+1 <= a[i]-m) ll = mm;
                else rr = mm-1;
            }
            c += ll+1;
            if (c > k) break;
        }
        if (c > k) l = m+1;
        else r = m;
    }
    LLI c = 0;
    for (i = 0; i < n; i++) {
        int ll = -1,rr = a[i]-1;
        while (ll < rr) {
            int mm = (ll+rr+1) / 2;
            if (3LL*mm*mm+3LL*mm+1 <= a[i]-l) ll = mm;
            else rr = mm-1;
        }
        int x = ll+1;
        b[i] = x,c += x;
    }
    if (c < k) {
        for (i = 0; i < n; i++) {
            if (b[i] < a[i]) vv.pb(mp(a[i]-3LL*b[i]*b[i]+3LL*b[i]+1,i));
        }
        sort(vv.begin(),vv.end(),greater<pair<LLI,int> >());
        for (i = 0; i < vv.size(); i++) {
            b[vv[i].second]++,c++;
            if (c == k) break;
        }
    }
    for (i = 0; i < n; i++) printf("%d ",b[i]);
    printf("\n");

    return 0;
}