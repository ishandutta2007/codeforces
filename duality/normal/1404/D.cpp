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

int p[1000000],l[1000000];
vi adjList[1000000];
int visited[1000000];
int doDFS(int u,int c) {
    if (visited[u] > 0) return 0;
    int i;
    visited[u] = c;
    for (i = 0; i < adjList[u].size(); i++) doDFS(adjList[u][i],c^3);
    return 0;
}
int main() {
    int n;
    cin >> n;

    int i;
    if (n & 1) {
        cout << "Second" << endl;
        for (i = 0; i < 2*n; i++) cin >> p[i];
        for (i = 0; i < n; i++) adjList[i].pb(i+n),adjList[i+n].pb(i);
        fill(l,l+n,-1);
        for (i = 0; i < 2*n; i++) {
            p[i]--;
            if (l[p[i]] == -1) l[p[i]] = i;
            else adjList[l[p[i]]].pb(i),adjList[i].pb(l[p[i]]);
        }
        LLI sum1 = 0,sum2 = 0;
        for (i = 0; i < 2*n; i++) {
            if (visited[i] == 0) doDFS(i,1);
            if (visited[i] == 1) sum1 += i+1;
            else sum2 += i+1;
        }
        if ((sum1 % (2*n)) == 0) {
            for (i = 0; i < 2*n; i++) {
                if (visited[i] == 1) cout << i+1 << " ";
            }
        }
        else {
            for (i = 0; i < 2*n; i++) {
                if (visited[i] == 2) cout << i+1 << " ";
            }
        }
        cout << endl;
        cin >> i;
    }
    else {
        cout << "First" << endl;
        for (i = 0; i < 2*n; i++) cout << 1+(i % n) << " ";
        cout << endl;
        cin >> i;
    }

    return 0;
}