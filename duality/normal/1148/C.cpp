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

int n;
int p[300000],inv[300000];
vpii sol;
int myswap(int i,int j) {
    if (i == j) return 0;
    if (i > j) swap(i,j);
    if (j-i >= n/2) sol.pb(mp(i,j));
    else if ((i < n/2) && (j < n/2)) {
        sol.pb(mp(i,n-1));
        sol.pb(mp(j,n-1));
        sol.pb(mp(i,n-1));
    }
    else if ((i >= n/2) && (j >= n/2)) {
        sol.pb(mp(0,i));
        sol.pb(mp(0,j));
        sol.pb(mp(0,i));
    }
    else {
        sol.pb(mp(0,j)),sol.pb(mp(i,n-1));
        sol.pb(mp(0,n-1));
        sol.pb(mp(0,j)),sol.pb(mp(i,n-1));
    }
    return 0;
}
int main() {
    int i;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),p[i]--,inv[p[i]] = i;

    for (i = 0; i < n; i++) {
        myswap(i,inv[i]);
        int x = i,y = inv[i];
        swap(p[x],p[y]);
        swap(inv[p[x]],inv[p[y]]);
    }
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d\n",sol[i].first+1,sol[i].second+1);

    return 0;
}