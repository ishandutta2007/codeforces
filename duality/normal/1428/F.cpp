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

char s[500001];
LLI ans = 0;
int findAns(int l,int r) {
    if (l > r) return 0;
    int i;
    vi z;
    for (i = l; i <= r; i++) {
        if (s[i] == '0') z.pb(i);
    }
    if (z.empty()) {
        int x = r-l+1;
        ans += (LLI) (x+2)*(x+1)*x/6;
        return 0;
    }
    else if (z.size() == r-l+1) return 0;

    int m = z[z.size()/2];
    findAns(l,m-1),findAns(m+1,r);
    int a = 0,c = 0;
    vi occ1(r-l+2),occ2(r-l+2);
    for (i = m; i <= r; i++) {
        if (s[i] == '0') c = 0;
        else c++;
        a = max(a,c),occ1[a]++;
    }
    a = c = 0;
    for (i = m; i >= l; i--) {
        if (s[i] == '0') c = 0;
        else c++;
        a = max(a,c),occ2[a]++;
    }
    int x = 0,y = 0;
    LLI s = 0;
    for (i = 0; i <= r-l+1; i++) {
        s += (LLI) x*y;
        x += occ1[i],y += occ2[i];
    }
    ans += (LLI) (r-l+1)*x*y-s;
    return 0;
}
int main() {
    int n;
    scanf("%d %s",&n,s);
    findAns(0,n-1);
    printf("%I64d\n",ans);

    return 0;
}