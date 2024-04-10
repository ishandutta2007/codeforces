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

vpii adjList[200000];
int size[200000],parent[200000];
int doDFS(int u,int p,int pw) {
    int i;
    size[u] = 1,parent[u] = pw;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) size[u] += doDFS(v,u,adjList[u][i].second);
    }
    return size[u];
}
int main() {
    int i;
    int t,k,a,b,c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&k);
        for (i = 0; i < 2*k-1; i++) {
            scanf("%d %d %d",&a,&b,&c);
            a--,b--;
            adjList[a].pb(mp(b,c));
            adjList[b].pb(mp(a,c));
        }
        doDFS(0,-1,0);

        LLI ans1 = 0,ans2 = 0;
        for (i = 1; i < 2*k; i++) {
            ans1 += (LLI) parent[i]*min(size[i],2*k-size[i]);
            if (size[i] & 1) ans2 += parent[i];
        }
        printf("%I64d %I64d\n",ans2,ans1);
        for (i = 0; i < 2*k; i++) adjList[i].clear();
    }

    return 0;
}