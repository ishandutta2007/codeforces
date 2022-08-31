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

int adjMat[18][18];
vector<vi> poss;
LLI dp[1 << 18][18],num[19][1 << 18],val[385],ans[1 << 17];
int main() {
    int i,j,n;
    char c;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf(" %c",&c),adjMat[i][j] = (c == '1');
    }

    int k;
    for (i = 0; i < (1 << (n-1)); i++) {
        vi v;
        int c = 1;
        for (j = 0; j < n-1; j++) {
            if (i & (1 << j)) c++;
            else v.pb(c),c = 1;
        }
        v.pb(c);
        for (j = 1; j < v.size(); j++) {
            if (v[j] < v[j-1]) break;
        }
        if (j == v.size()) poss.pb(v);
    }
    sort(poss.begin(),poss.end());
    for (i = 0; i < n; i++) dp[1 << i][i] = 1;
    for (i = 0; i < (1 << n); i++) {
        int b = __builtin_popcount(i);
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (k = 0; k < n; k++) {
                    if ((j != k) && (i & (1 << k)) && adjMat[j][k]) dp[i][j] += dp[i^(1 << j)][k];
                }
                num[b][i] += dp[i][j];
            }
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < (1 << n); k++) {
                if (k & (1 << j)) num[i][k] += num[i][k^(1 << j)];
            }
        }
    }
    for (i = 0; i < poss.size(); i++) {
        for (j = 0; j < (1 << n); j++) {
            int b = __builtin_popcount(j);
            LLI w = 1;
            for (k = 0; k < poss[i].size(); k++) w *= num[poss[i][k]][j];
            if ((n-b) & 1) val[i] -= w;
            else val[i] += w;
        }
    }
    for (i = 0; i < (1 << (n-1)); i++) {
        vi v;
        int c = 1;
        for (j = 0; j < n-1; j++) {
            if (i & (1 << j)) c++;
            else v.pb(c),c = 1;
        }
        v.pb(c),sort(v.begin(),v.end());
        ans[i] = val[lower_bound(poss.begin(),poss.end(),v)-poss.begin()];
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < (1 << (n-1)); j++) {
            if (!(j & (1 << i))) ans[j] -= ans[j^(1 << i)];
        }
    }
    for (i = 0; i < (1 << (n-1)); i++) printf("%lld ",ans[i]);
    printf("\n");

    return 0;
}