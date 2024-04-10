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

bitset<2000> adj[2000];
int out[2000],sorted[2000];
bitset<2000> visited;
queue<int> Q;
int strong(int n) {
    int i,sum = 0;
    for (i = 0; i < n; i++) sorted[i] = out[i];
    sort(sorted,sorted+n);
    for (i = 0; i < n-1; i++) {
        sum += sorted[i];
        if (sum == i*(i+1)/2) return 0;
    }
    return 1;
}
int main() {
    int i,j;
    int n;
    char c;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf(" %c",&c),adj[i][j] = (c == '1'),out[i] += adj[i][j];
    }

    if (n < 18) {
        int k,m = 1e9,ways = 0;
        for (i = 0; i < (1 << n); i++) {
            int c = 0;
            for (j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (k = 0; k < n; k++) {
                        if (adj[j][k]) out[j]--,out[k]++;
                        else out[j]++,out[k]--;
                        adj[j][k] = !adj[j][k],adj[k][j] = !adj[k][j];
                    }
                    c++;
                }
            }
            if (strong(n)) {
                if (c < m) m = c,ways = 1;
                else if (c == m) ways++;
            }
            for (j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (k = 0; k < n; k++) {
                        if (adj[j][k]) out[j]--,out[k]++;
                        else out[j]++,out[k]--;
                        adj[j][k] = !adj[j][k],adj[k][j] = !adj[k][j];
                    }
                }
            }
        }
        if (m == 1e9) printf("-1\n");
        else {
            for (i = 1; i <= m; i++) ways *= i;
            printf("%d %d\n",m,ways);
        }
        return 0;
    }
    if (strong(n)) {
        printf("0 1\n");
        return 0;
    }
    int ways = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j]) out[i]--,out[j]++;
            else out[i]++,out[j]--;
            adj[i][j] = !adj[i][j],adj[j][i] = !adj[j][i];
        }
        if (strong(n)) ways++;
        for (j = 0; j < n; j++) {
            if (adj[i][j]) out[i]--,out[j]++;
            else out[i]++,out[j]--;
            adj[i][j] = !adj[i][j],adj[j][i] = !adj[j][i];
        }
    }
    printf("1 %d\n",ways);

    return 0;
}