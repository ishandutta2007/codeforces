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

pii p[300000];
LLI ans[300000];
int order[300000];
bool comp(int a,int b) {
    return p[a].second < p[b].second;
}
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].first,&p[i].second),p[i].second -= p[i].first;
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        ans[u] -= (LLI) p[u].first+p[v].first+min(p[u].second,p[v].second);
        ans[v] -= (LLI) p[u].first+p[v].first+min(p[u].second,p[v].second);
    }

    LLI sum = 0,sum2 = 0;
    for (i = 0; i < n; i++) order[i] = i,sum += p[i].first;
    sort(order,order+n,comp);
    for (i = 0; i < n; i++) {
        int u = order[i];
        ans[u] += sum-p[u].first+(LLI) p[u].first*(n-1);
        ans[u] += (LLI) p[u].second*(n-i-1);
        ans[u] += sum2;
        sum2 += p[u].second;
    }
    for (i = 0; i < n; i++) printf("%I64d ",ans[i]);
    printf("\n");

    return 0;
}