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

int x[100000],y[100000];
int ans[100000];
vi adjList[100000];
set<int> S;
LLI mag(int a,int b) {
    return (LLI) a*a+(LLI) b*b;
}
int doDFS(int u) {
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        ans[adjList[u][i]] = -ans[u];
        doDFS(adjList[u][i]);
    }
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&x[i],&y[i]),S.insert(i);

    int j;
    while (S.size() > 10) {
        vi v;
        for (auto it = S.begin(); it != S.end(); it++) {
            v.pb(*it);
            if (v.size() > 8) break;
        }
        for (i = 0; i < v.size(); i++) {
            for (j = i+1; j < v.size(); j++) {
                if (mag(x[v[i]]-x[v[j]],y[v[i]]-y[v[j]]) <= max(mag(x[v[i]],y[v[i]]),mag(x[v[j]],y[v[j]]))) break;
            }
            if (j < v.size()) break;
        }
        adjList[v[i]].pb(v[j]);
        x[v[i]] -= x[v[j]],y[v[i]] -= y[v[j]];
        S.erase(v[j]);
    }
    vi v;
    for (auto it = S.begin(); it != S.end(); it++) v.pb(*it);
    for (i = 0; i < (1 << v.size()); i++) {
        int xx = 0,yy = 0;
        for (j = 0; j < v.size(); j++) {
            if (i & (1 << j)) xx += x[v[j]],yy += y[v[j]];
            else xx -= x[v[j]],yy -= y[v[j]];
        }
        if (mag(xx,yy) < (1.5e6)*(1.5e6)) {
            for (j = 0; j < v.size(); j++) {
                if (i & (1 << j)) ans[v[j]] = 1;
                else ans[v[j]] = -1;
            }
            break;
        }
    }
    for (i = 0; i < v.size(); i++) doDFS(v[i]);
    for (i = 0; i < n; i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}