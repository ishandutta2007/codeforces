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

int a[200000],b[200000];
int in[200000],visited[200000];
vpii vv;
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        fill(in,in+n,0);
        for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--,in[a[i]]++,b[i] = a[i];

        for (i = 0; i < n; i++) {
            if (in[i] == 0) {
                int u = i;
                while (!visited[a[u]]) b[u] = a[u],visited[u] = 1,u = b[u];
                visited[u] = 1;
                if (a[u] == i) b[u] = a[u];
                else vv.pb(mp(i,u));
            }
        }
        if (!vv.empty()) {
            for (i = 0; i < vv.size(); i++) b[vv[i].second] = vv[(i+1) % vv.size()].first;
        }
        vv.clear();
        int k = 0;
        for (i = 0; i < n; i++) k += b[i] == a[i];
        printf("%d\n",k);
        for (i = 0; i < n; i++) printf("%d ",b[i]+1);
        printf("\n");
        fill(visited,visited+n,0);
    }

    return 0;
}