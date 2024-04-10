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

pii p[100000];
vi v;
vpii edges;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i].first),p[i].second = i+1;
    sort(p,p+n,greater<pii>());

    v.pb(2*p[0].second-1);
    for (i = 0; i < p[0].first-1; i++) v.pb(2*p[i+1].second-1);
    v.pb(2*p[0].second);
    for (i = 1; i < v.size(); i++) edges.pb(mp(v[i-1],v[i]));
    for (i = 1; i < p[0].first; i++) {
        if (v.size()-i-1 >= p[i].first) edges.pb(mp(v[i+p[i].first-1],2*p[i].second));
        else edges.pb(mp(v.back(),2*p[i].second)),v.pb(2*p[i].second);
    }
    for (; i < n; i++) {
        if (p[i].first == 1) edges.pb(mp(v.back(),2*p[i].second-1)),edges.pb(mp(2*p[i].second-1,2*p[i].second));
        else edges.pb(mp(v[0],2*p[i].second-1)),edges.pb(mp(v[p[i].first-2],2*p[i].second));
    }
    for (i = 0; i < edges.size(); i++) printf("%d %d\n",edges[i].first,edges[i].second);

    return 0;
}