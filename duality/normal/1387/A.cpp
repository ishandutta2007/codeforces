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

vpii adjList[100000];
int visited[100000],ans[100000];
pii f[100000];
vi vv,vv2;
int no = 0,must;
int doDFS(int u,pii ff) {
    if (visited[u]) {
        if (f[u].first == ff.first) {
            if (f[u].second != ff.second) no = 1;
        }
        else {
            if (must == 1e9) must = (ff.second-f[u].second)/(f[u].first-ff.first);
            else if ((ff.second-f[u].second)/(f[u].first-ff.first) != must) no = 1;
        }
        return 0;
    }
    int i;
    visited[u] = 1,f[u] = ff,vv.pb(u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        doDFS(v,mp(-ff.first,adjList[u][i].second-ff.second));
    }
    return 0;
}
int main() {
    int i;
    int N,M;
    int a,b,c;
    scanf("%d %d",&N,&M);
    for (i = 0; i < M; i++) {
        scanf("%d %d %d",&a,&b,&c);
        a--,b--;
        adjList[a].pb(mp(b,2*c));
        adjList[b].pb(mp(a,2*c));
    }

    int j;
    for (i = 0; i < N; i++) {
        if (!visited[i]) {
            must = 1e9,vv.clear();
            doDFS(i,mp(1,0));
            if (no) break;
            else if (must != 1e9) {
                for (j = 0; j < vv.size(); j++) ans[vv[j]] = f[vv[j]].first*must+f[vv[j]].second;
            }
            else {
                for (j = 0; j < vv.size(); j++) vv2.pb(-f[vv[j]].first*f[vv[j]].second);
                nth_element(vv2.begin(),vv2.begin()+(vv2.size()-1)/2,vv2.end());
                must = vv2[(vv2.size()-1)/2];
                for (j = 0; j < vv.size(); j++) ans[vv[j]] = f[vv[j]].first*must+f[vv[j]].second;
                vv2.clear();
            }
        }
    }
    if (no) printf("NO\n");
    else {
        printf("YES\n");
        for (i = 0; i < N; i++) {
            if (ans[i] >= 0) printf("%d.%c ",ans[i]/2,(ans[i] & 1) ? '5':'0');
            else printf("-%d.%c ",(-ans[i])/2,((-ans[i]) & 1) ? '5':'0');
        }
        printf("\n");
    }

    return 0;
}