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

int u[300000],v[300000],d[300000];
LLI debt[300000];
vector<pair<pii,LLI> > sol;
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) scanf("%d %d %d",&u[i],&v[i],&d[i]),u[i]--,v[i]--;

    for (i = 0; i < m; i++) debt[u[i]] += d[i],debt[v[i]] -= d[i];
    vi a,b;
    for (i = 0; i < n; i++) {
        if (debt[i] > 0) a.pb(i);
        else if (debt[i] < 0) b.pb(i);
    }
    while (!a.empty()) {
        LLI x = debt[a.back()];
        LLI y = -debt[b.back()];
        sol.pb(mp(mp(a.back(),b.back()),min(x,y)));
        debt[a.back()] -= min(x,y),debt[b.back()] += min(x,y);
        while (!a.empty() && (debt[a.back()] == 0)) a.pop_back();
        while (!b.empty() && (debt[b.back()] == 0)) b.pop_back();
    }
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d %I64d\n",sol[i].first.first+1,sol[i].first.second+1,sol[i].second);

    return 0;
}