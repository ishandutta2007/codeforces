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

int a[50][50],b[50][50],match[100];
vpii order[50];
int p[50];
int main() {
    int i,j;
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) cin >> a[i][j],b[j][i] = a[i][j];
        }

        char c;
        int x;
        cout << "B" << endl;
        cin >> c >> x,x--;
        if ((x < n) && (c == 'D')) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) b[i][j] = -b[i][j];
            }
        }
        else if ((x < n) && (c == 'I')) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) a[i][j] = -a[i][j];
            }
        }
        else if ((x >= n) && (c == 'D')) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) a[i][j] = -a[i][j];
            }
        }
        else {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) b[i][j] = -b[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            order[i].clear(),p[i] = 0;
            for (j = 0; j < n; j++) order[i].pb(mp(a[i][j],j));
            sort(order[i].begin(),order[i].end(),greater<pii>());
        }
        for (i = 0; i < 2*n; i++) match[i] = -1;
        while (1) {
            for (i = 0; i < n; i++) {
                if (match[i] == -1) {
                    int v = order[i][p[i]++].second;
                    if (match[v+n] == -1) match[i] = v+n,match[v+n] = i;
                    else if (b[v][i] > b[v][match[v+n]])
                        match[match[v+n]] = -1,match[i] = v+n,match[v+n] = i;
                    break;
                }
            }
            if (i == n) break;
        }
        cout << match[x]+1 << endl;
        while (1) {
            cin >> x;
            if (x == -1) break;
            else cout << match[x-1]+1 << endl;
        }
    }

    return 0;
}