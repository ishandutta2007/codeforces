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

int u[180000],v[180000],w[180000];
vpii vv[600];
LLI dist[600][600],dist2[600];
int yes[180000];
int main() {
    int i,j;
    int n,m,q;
    int a,b,l;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) dist[i][j] = 1e18;
        dist[i][i] = 0;
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        u[i]--,v[i]--;
        dist[u[i]][v[i]] = dist[v[i]][u[i]] = w[i];
    }
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&a,&b,&l);
        a--,b--;
        vv[a].pb(mp(b,l));
        vv[b].pb(mp(a,l));
    }

    int k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) dist2[j] = 1e18;
        for (j = 0; j < vv[i].size(); j++) {
            for (k = 0; k < n; k++) dist2[k] = min(dist2[k],dist[k][vv[i][j].first]-vv[i][j].second);
        }
        for (j = 0; j < m; j++) {
            if (dist[i][u[j]]+dist2[v[j]]+w[j] <= 0) yes[j] = 1;
            if (dist[i][v[j]]+dist2[u[j]]+w[j] <= 0) yes[j] = 1;
        }
    }
    a = 0;
    for (i = 0; i < m; i++) a += yes[i];
    printf("%d\n",a);

    return 0;
}