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

int a[200000],b[200000],num[200000];
deque<int> occ[200000];
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--,occ[a[i]].pb(i),num[i] = 1;
        for (i = 0; i < n; i++) scanf("%d",&b[i]),b[i]--;

        int p = 0,no = 0;
        for (i = 0; i < n; i++) {
            while ((p < n) && (a[p] != b[i])) {
                if (occ[a[p]].size() == 1) {
                    no = 1;
                    break;
                }
                num[occ[a[p]][1]] += num[p],num[p] = 0;
                occ[a[p]].pop_front(),p++;
            }
            if (no || (p == n)) break;
            num[p]--;
            while (!occ[a[p]].empty() && (num[occ[a[p]][0]] == 0)) occ[a[p]].pop_front();
            while ((p < n) && (num[p] == 0)) p++;
        }
        if (i < n) printf("NO\n");
        else printf("YES\n");

        for (i = 0; i < n; i++) occ[i].clear();
    }

    return 0;
}