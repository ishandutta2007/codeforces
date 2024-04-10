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

int a[1200],used[1200],pre[1201];
int dp[1200][1200][2],p[1200][1200][2];
vi findMove(int l,int r,int c,int c2) {
    if (pre[r+1]-pre[l] == 0) return vi();
    if (c2 == -1) c2 = dp[l][r][1];

    vi v = findMove(l,p[l][p[l][r][c2]-1][c2]-1,c,-1);
    if (!v.empty()) return v;
    v = findMove(p[l][p[l][r][c2]-1][c2]+1,p[l][r][c2]-1,c,-1);
    if (!v.empty()) return v;
    v = findMove(p[l][r][c2]+1,p[p[l][r][c2]+1][r][c2]-1,c,-1);
    if (!v.empty()) return v;
    v = findMove(p[p[l][r][c2]+1][r][c2]+1,r,c,-1);
    if (!v.empty()) return v;
    if (pre[p[p[l][r][c2]+1][r][c2]+1]-pre[p[l][p[l][r][c2]-1][c2]] == 3) {
        if (a[p[l][r][c2]] == c) {
            vi v;
            v.pb(p[l][p[l][r][c2]-1][c2]);
            v.pb(p[l][r][c2]);
            v.pb(p[p[l][r][c2]+1][r][c2]);
            return v;
        }
        else return vi();
    }
    else return vi();
}
int main() {
    int i;
    int n,x;
    scanf("%d",&n);
    for (i = 0; i < 3*n; i++) scanf("%d",&x),a[x-1] = 1;

    int j,k,l;
    for (i = 1; i <= 6*n; i++) {
        for (j = 0; j <= 6*n-i; j++) {
            k = j+i-1;
            if ((i % 3) == 0) {
                for (l = j+1; l < k; l += 3) {
                    if (dp[j][l-1][a[l]] && dp[l+1][k][a[l]]) dp[j][k][a[l]] = 1,p[j][k][a[l]] = l;
                }
            }
            else if ((i % 3) == 1) {
                if (i == 1) dp[j][k][a[j]] = 1,p[j][k][a[j]] = j;
                else {
                    for (l = j; l <= k; l += 3) {
                        if (((l == j) || dp[j][l-1][0] || dp[j][l-1][1]) && ((l == k) || dp[l+1][k][0] || dp[l+1][k][1]))
                            dp[j][k][a[l]] = 1,p[j][k][a[l]] = l;
                    }
                }
            }
        }
    }
    for (i = 1; i <= 6*n; i++) pre[i] = i;
    for (i = 1; i <= 2*n; i++) {
        vi v = findMove(0,6*n-1,i & 1,0);
        used[v[0]] = used[v[1]] = used[v[2]] = 1;
        for (j = 0; j < 6*n; j++) pre[j+1] = pre[j]+!used[j];
        printf("%d %d %d\n",v[0]+1,v[1]+1,v[2]+1);
    }

    return 0;
}