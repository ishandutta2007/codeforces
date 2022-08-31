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

__int128 ans = 0;
LLI sum = 0;
char s[600000];
int sparse[600000][20],logg[600001],lps[600001][21];
int query(int s,int e) {
    int l = logg[e-s+1];
    return min(sparse[s][l],sparse[e-(1 << l)+1][l]);
}
map<int,int> M;
int main() {
    int i,j;
    int n,w;
    char c;
    scanf("%d",&n);
    memset(lps,-1,sizeof(lps));
    for (i = 2; i <= n; i++) logg[i] = logg[i/2] + 1;
    for (i = 0; i < n; i++) {
        scanf(" %c %d",&c,&w);
        c = 'a'+((c-'a'+(ans % 26)) % 26);
        w ^= ans & ((1 << 30)-1);

        s[i] = c,j = lps[i][0];
        while ((j >= 0) && (s[i] != s[j])) j = lps[j][0];
        lps[i+1][0] = j+1;
        for (j = 1; lps[i+1][j-1] != -1; j++) lps[i+1][j] = lps[lps[i+1][j-1]][j-1];
        sparse[i][0] = w;
        for (j = 1; (1 << j) <= i+1; j++) sparse[i-(1 << j)+1][j] = min(sparse[i-(1 << j)+1][j-1],sparse[i-(1 << (j-1))+1][j-1]);
        if (s[i] == s[0]) M[w]++,sum += w;
        while ((--M.end())->first > w) {
            sum -= (LLI) ((--M.end())->first-w)*(--M.end())->second;
            M[w] += (--M.end())->second;
            M.erase(--M.end());
        }
        int x = lps[i][0];
        while (x > 0) {
            while ((x > 0) && (s[i] != s[x])) {
                int z = query(i-x,i);
                M[z]--,sum -= z;
                if (M[z] == 0) M.erase(z);
                x = lps[x][0];
            }
            for (j = 20; j >= 0; j--) {
                if ((lps[x][j] >= 0) && (lps[x][j] == lps[x+1][j]-1)) x = lps[x][j];
            }
            x = lps[x][0];
        }

        ans += sum;
        if (ans >= 1e18) printf("%I64d%018I64d\n",(LLI) (ans / ((LLI) 1e18)),(LLI) (ans % ((LLI) 1e18)));
        else printf("%I64d\n",(LLI) ans);
    }

    return 0;
}