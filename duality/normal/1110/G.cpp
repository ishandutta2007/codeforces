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

vi adjList[2000000];
int main() {
    int i,j;
    int T,t;
    int n,u,v;
    char c;
    scanf("%d",&T);
    for (t = 0; t < T; t++) {
        scanf("%d",&n);
        for (i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        int nn = n;
        for (i = 0; i < nn; i++) {
            scanf(" %c",&c);
            if (c == 'W') {
                adjList[i].pb(n),adjList[n].pb(i);
                adjList[n].pb(n+1),adjList[n+1].pb(n);
                adjList[n].pb(n+2),adjList[n+2].pb(n);
                n += 3;
            }
        }

        int c = 0;
        for (i = 0; i < n; i++) {
            if (adjList[i].size() >= 4) break;
            else if (adjList[i].size() >= 3) {
                c++;
                int c2 = 0;
                for (j = 0; j < adjList[i].size(); j++) {
                    v = adjList[i][j];
                    if (adjList[v].size() >= 2) c2++;
                }
                if (c2 >= 2) break;
            }
        }
        if ((i < n) || ((c == 2) && (n & 1))) printf("White\n");
        else printf("Draw\n");
        for (i = 0; i < n; i++) adjList[i].clear();
    }

    return 0;
}