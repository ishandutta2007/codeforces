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

int c[10000];
int a[100],b[100];
int seen[100];
int main() {
    int i;
    int n,k;
    cin >> n >> k;
    for (i = 0; i < n*k; i++) cin >> c[i],c[i]--;
    
    int j;
    for (i = 0; i < n; i++) a[i] = b[i] = -1;
    while (1) {
        for (i = 0; i < n*k; i++) {
            if ((c[i] != -1) && (a[c[i]] != -1)) c[i] = -1;
        }
        for (i = 0; i < n*k; i++) {
            if (c[i] != -1) break;
        }
        if (i == n*k) break;
        int l = 0;
        fill(seen,seen+n,-1);
        for (i = 0; i < n*k; i++) {
            if (c[i] != -1) {
                if (seen[c[i]] == -1) seen[c[i]] = i;
                else if (a[c[i]] == -1) {
                    a[c[i]] = seen[c[i]],b[c[i]] = i;
                    for (j = l; j <= b[c[i]]; j++) seen[c[j]] = -1;
                    l = b[c[i]]+1;
                }
            }
        }
    }
    for (i = 0; i < n; i++) cout << a[i]+1 << " " << b[i]+1 << endl;
    
    return 0;
}