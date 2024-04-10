#define DEBUG 1

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

int a[100000];
pii sorted[100000];
set<pii> S;
multiset<int> S2;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),sorted[i] = mp(a[i],i);
    sort(sorted,sorted+n);

    int m = sorted[0].first,l = 0;
    S.insert(mp(0,n-1)),S2.insert(n);
    for (i = n-1; i >= 0; i--) {
        if ((i == n-1) || (sorted[i+1].first != sorted[i].first)) {
            if (*S2.begin() == *(--S2.end())) {
                if (S2.size() > l) m = sorted[i].first+1,l = S2.size();
                else if (S2.size() == l) {
                    if (sorted[i].first+1 < m) m = sorted[i].first+1;
                }
            }
        }
        auto it = S.upper_bound(mp(sorted[i].second,MAX_VAL));
        it--;
        S2.erase(S2.find(it->second-it->first+1));
        if (sorted[i].second != it->first) {
            S.insert(mp(it->first,sorted[i].second-1));
            S2.insert(sorted[i].second-it->first);
        }
        if (sorted[i].second != it->second) {
            S.insert(mp(sorted[i].second+1,it->second));
            S2.insert(it->second-sorted[i].second);
        }
        S.erase(it);
    }
    printf("%d\n",m);

    return 0;
}