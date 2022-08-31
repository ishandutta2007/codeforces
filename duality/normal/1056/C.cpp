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

int p[2000];
int seen[2000];
vpii pairs;
int main() {
    int i;
    int n,m,t,a,b;
    cin >> n >> m;
    for (i = 0; i < 2*n; i++) cin >> p[i];
    for (i = 0; i < m; i++) {
        cin >> a >> b,a--,b--;
        pairs.pb(mp(a,b));
    }
    cin >> t;

    int j;
    if (t == 1) {
        for (i = 0; i < m; i++) {
            if (p[pairs[i].first] > p[pairs[i].second]) cout << pairs[i].first+1 << endl;
            else cout << pairs[i].second+1 << endl;
            int x;
            cin >> x;
            seen[pairs[i].first] = seen[pairs[i].second] = 1;
        }
        for (i = 0; i < n-m; i++) {
            int m = -1;
            for (j = 0; j < 2*n; j++) {
                if (!seen[j] && ((m == -1) || (p[j] > p[m]))) m = j;
            }
            int x;
            cout << m+1 << endl;
            cin >> x;
            seen[m] = seen[x-1] = 1;
        }
    }
    else {
        int x;
        while (1) {
            cin >> x,x--,seen[x] = 1;
            for (i = 0; i < m; i++) {
                if (pairs[i].first == x) {
                    cout << pairs[i].second+1 << endl;
                    seen[pairs[i].second] = 1;
                    break;
                }
                if (pairs[i].second == x) {
                    cout << pairs[i].first+1 << endl;
                    seen[pairs[i].first] = 1;
                    break;
                }
            }
            if (i == m) {
                for (i = 0; i < m; i++) {
                    if (!seen[pairs[i].first]) {
                        if (p[pairs[i].first] > p[pairs[i].second]) cout << pairs[i].first+1 << endl;
                        else cout << pairs[i].second+1 << endl;
                        cin >> x;
                        seen[pairs[i].first] = seen[pairs[i].second] = 1;
                    }
                }
                int m = -1;
                for (j = 0; j < 2*n; j++) {
                    if (!seen[j] && ((m == -1) || (p[j] > p[m]))) m = j;
                }
                cout << m+1 << endl;
                seen[m] = 1;
            }
            for (i = 0; i < 2*n; i++) {
                if (!seen[i]) break;
            }
            if (i == 2*n) break;
        }
    }

    return 0;
}