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

char s[100000];
int trie[3][1001][26],parent[3][1001];
int num[3];
int state[1001][3];
int nxt[26][100001];
int dp[350*350*350];
int getIndex(int a,int b,int c) {
    return a+b*(num[0]+1)+c*(num[0]+1)*(num[1]+1);
}
int main() {
    int i,j;
    int n,q,p;
    char c;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);
    for (i = 0; i < q; i++) {
        scanf(" %c",&c);
        if (c == '+') {
            scanf("%d %c",&p,&c),p--;
            c -= 'a';

            for (j = 0; j < 3; j++) state[i+1][j] = state[i][j];
            if (trie[p][state[i][p]][c] == 0) {
                trie[p][state[i][p]][c] = ++num[p];
                parent[p][num[p]] = state[i][p];
            }
            state[i+1][p] = trie[p][state[i][p]][c];
        }
        else {
            scanf("%d",&p),p--;

            for (j = 0; j < 3; j++) state[i+1][j] = state[i][j];
            state[i+1][p] = parent[p][state[i][p]];
        }
    }

    for (i = 0; i < 26; i++) {
        nxt[i][n] = n;
        for (j = n-1; j >= 0; j--) {
            if (s[j] == i+'a') nxt[i][j] = j;
            else nxt[i][j] = nxt[i][j+1];
        }
    }

    int k;
    fill(dp,dp+(num[0]+1)*(num[1]+1)*(num[2]+1),n+1);
    dp[0] = 0;
    for (i = 0; i < (num[0]+1)*(num[1]+1)*(num[2]+1); i++) {
        int a = i % (num[0]+1);
        int b = (i/(num[0]+1)) % (num[1]+1);
        int c = (i/(num[0]+1)/(num[1]+1));
        //cout<<a<<","<<b<<","<<c<<": "<<dp[i]<<endl;
        if (dp[i] >= n) continue;

        for (k = 0; k < 26; k++) {
            if (trie[0][a][k] != 0) {
                int p = getIndex(trie[0][a][k],b,c);
                dp[p] = min(dp[p],nxt[k][dp[i]]+1);
            }
        }
        for (k = 0; k < 26; k++) {
            if (trie[1][b][k] != 0) {
                int p = getIndex(a,trie[1][b][k],c);
                dp[p] = min(dp[p],nxt[k][dp[i]]+1);
            }
        }
        for (k = 0; k < 26; k++) {
            if (trie[2][c][k] != 0) {
                int p = getIndex(a,b,trie[2][c][k]);
                dp[p] = min(dp[p],nxt[k][dp[i]]+1);
            }
        }
    }
    for (i = 0; i < q; i++) {
        if (dp[getIndex(state[i+1][0],state[i+1][1],state[i+1][2])] <= n) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}