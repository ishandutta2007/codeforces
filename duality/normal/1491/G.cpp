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

int n;
int c[200000],pos[200000];
vector<vi> cycles;
int visited[200000];
vpii ans;
int doSwap(int a,int b) {
    ans.pb(mp(pos[a],pos[b]));
    swap(c[pos[a]],c[pos[b]]);
    c[pos[a]] *= -1,c[pos[b]] *= -1;
    swap(pos[a],pos[b]);
    printArr(c,n);
    return 0;
}
int main() {
    int i;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&c[i]),c[i]--,pos[c[i]] = i;

    int j;
    for (i = 0; i < n; i++) {
        if ((c[i] != i) && !visited[i]) {
            int u = i;
            cycles.pb(vi());
            while (!visited[u]) cycles.back().pb(c[u]),visited[u] = 1,u = c[u];
        }
    }
    for (i = 0; i+1 < cycles.size(); i += 2) {
        vi a = cycles[i],b = cycles[i+1];
        doSwap(a[0],b[0]);
        for (j = 0; j < b.size()-2; j++) doSwap(b[j],b[j+1]);
        doSwap(b.back(),a[1]);
        for (j = 2; j < a.size(); j++) doSwap(a[j-1],a[j]);
        doSwap(a[0],b.back());
        doSwap(b[b.size()-2],a.back());
    }
    if (i < cycles.size()) {
        vi a = cycles[i];
        if (a.size() > 2) {
            doSwap(a[0],a.back());
            doSwap(a.back(),a[1]);
            for (i = 2; i < a.size()-1; i++) doSwap(a[i-1],a[i]);
            doSwap(a[0],a.back());
            doSwap(a[a.size()-2],a.back());
        }
        else {
            int u;
            if ((a[0] != 0) && (a[1] != 0)) u = 0;
            if ((a[0] != 1) && (a[1] != 1)) u = 1;
            if ((a[0] != 2) && (a[1] != 2)) u = 2;
            doSwap(u,a[0]);
            doSwap(a[0],a[1]);
            doSwap(u,a[1]);
        }
    }
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);

    return 0;
}