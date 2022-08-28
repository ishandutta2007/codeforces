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

vi adjList[1000];
int yes[1000];
vi his,vv;
int doDFS(int u,int p) {
    if (yes[u]) {
        vv.pb(u);
        return 0;
    }
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u);
    }
    return 0;
}
int main() {
    int i,j;
    int t,n,a,b,k1,k2;
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < 1000; i++) adjList[i].clear(),yes[i] = 0;
        for (i = 0; i < n-1; i++) {
            cin >> a >> b;
            a--,b--;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }
        cin >> k1;
        for (i = 0; i < k1; i++) cin >> a,yes[a-1] = 1;
        cin >> k2,his.resize(k2);
        for (i = 0; i < k2; i++) cin >> his[i],his[i]--;

        int x;
        cout << "B " << his[0]+1 << endl;
        cin >> x,x--;
        if (yes[x]) {
            cout << "C " << x+1 << endl;
            continue;
        }
        else {
            vv.clear();
            doDFS(x,-1);
            for (i = 0; i < vv.size(); i++) {
                cout << "A " << vv[i]+1 << endl;
                cin >> x,x--;
                for (j = 0; j < his.size(); j++) {
                    if (his[j] == x) break;
                }
                if (j < his.size()) {
                    cout << "C " << vv[i]+1 << endl;
                    break;
                }
            }
            if (i == vv.size()) {
                cout << "C " << -1 << endl;
                continue;
            }
        }
    }

    return 0;
}