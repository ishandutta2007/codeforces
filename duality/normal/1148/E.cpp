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

pii s[300000];
int t[300000];
vi S;
vector<pair<pii,int> > sol;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&s[i].first),s[i].second = i;
    for (i = 0; i < n; i++) scanf("%d",&t[i]);
    sort(s,s+n),sort(t,t+n);

    LLI sum = 0;
    for (i = 0; i < n; i++) s[i].first = t[i]-s[i].first;
    for (i = 0; i < n; i++) {
        sum += s[i].first;
        if (sum < 0) {
            printf("NO\n");
            return 0;
        }
    }
    if (sum != 0) {
        printf("NO\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (s[i].first > 0) S.pb(i);
        else {
            while (s[i].first < 0) {
                int d = min(s[S.back()].first,-s[i].first);
                s[S.back()].first -= d,s[i].first += d;
                sol.pb(mp(mp(s[S.back()].second,s[i].second),d));
                if (s[S.back()].first == 0) S.pop_back();
            }
        }
    }
    printf("YES\n%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d %d\n",sol[i].first.first+1,sol[i].first.second+1,sol[i].second);

    return 0;
}