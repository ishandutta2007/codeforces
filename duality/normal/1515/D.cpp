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

int c[200000];
map<int,int> L,R;
int main() {
    int i;
    int t,n,l,r;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&l,&r);
        for (i = 0; i < n; i++) scanf("%d",&c[i]),c[i]--;

        for (i = 0; i < n; i++) {
            if (i < l) L[c[i]]++;
            else R[c[i]]++;
        }
        if (l > r) swap(L,R),swap(l,r);
        for (auto it = L.begin(); it != L.end(); it++) {
            int m = min(it->second,R[it->first]);
            it->second -= m,R[it->first] -= m;
        }
        int ans = 0,diff = r-l;
        for (auto it = R.begin(); it != R.end(); it++) {
            int m = min(diff,it->second);
            if (m & 1) m--;
            ans += m/2,diff -= m,it->second -= m;
        }
        for (auto it = L.begin(); it != L.end(); it++) ans += it->second;
        ans += diff;
        printf("%d\n",ans);
        L.clear(),R.clear();
    }

    return 0;
}