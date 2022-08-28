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

int p[2000],c[2000];
vi adjList[2000];
int size[2000];
vi subn[2000];
vi order;
int doDFS(int u) {
    int i,j;
    size[u] = 1,subn[u].pb(u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        size[u] += doDFS(v);
        for (j = 0; j < subn[v].size(); j++) subn[u].pb(subn[v][j]);
    }
    order.pb(u);
    return size[u];
}
int a[2000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d %d",&p[i],&c[i]);
        p[i]--;
        if (p[i] != -1) adjList[p[i]].pb(i);
    }
    for (i = 0; i < n; i++) {
        if (p[i] == -1) doDFS(i);
    }

    for (i = 0; i < n; i++) {
        if (c[i] >= size[i]) {
            printf("NO\n");
            return 0;
        }
    }
    int j;
    for (i = 0; i < n; i++) {
        int u = order[i];
        vi sub;
        for (j = 1; j < subn[u].size(); j++) sub.pb(a[subn[u][j]]);
        sort(sub.begin(),sub.end());
        int x = (c[u] == sub.size()) ? i+1:sub[c[u]];
        for (j = 1; j < subn[u].size(); j++) {
            if (a[subn[u][j]] >= x) a[subn[u][j]]++;
        }
        a[u] = x;
    }
    printf("YES\n");
    for (i = 0; i < n; i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}