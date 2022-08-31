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

int a[200000];
vi adjList[200000];
int d1[200000],d2[200000];
queue<int> Q;
pii p[200000];
int main() {
    int i;
    int n,m,k;
    int x,y;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < k; i++) scanf("%d",&a[i]),a[i]--;
    for (i = 0; i < m; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        adjList[x].pb(y);
        adjList[y].pb(x);
    }

    fill(d1,d1+n,-1);
    d1[0] = 0,Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (d1[v] == -1) {
                d1[v] = d1[u]+1;
                Q.push(v);
            }
        }
    }
    fill(d2,d2+n,-1);
    d2[n-1] = 0,Q.push(n-1);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (d2[v] == -1) {
                d2[v] = d2[u]+1;
                Q.push(v);
            }
        }
    }

    int ans = 0,mm = 0;
    for (i = 0; i < k; i++) p[i] = mp(d2[a[i]]-d1[a[i]],d1[a[i]]);
    sort(p,p+k);
    for (i = k-1; i >= 0; i--) {
        if (i < k-1) ans = max(ans,p[i].second+mm+1+p[i].first);
        mm = max(mm,p[i].second);
    }
    printf("%d\n",min(ans,d1[n-1]));

    return 0;
}