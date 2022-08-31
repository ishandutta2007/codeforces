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

char s[1000];
int num = 0;
pii pos[1000005];
int trie[1000005][26];
vpii order;
int doDFS(int u) {
    int i;
    if (u > 0) order.pb(pos[u]);
    for (i = 0; i < 26; i++) {
        if (trie[u][i] != 0) doDFS(trie[u][i]);
    }
    return 0;
}
int poss[1000];
LLI dp[1000][1001],suff[1002];
int main() {
    int i;
    int n,m;
    LLI k;
    scanf("%d %d %I64d",&n,&m,&k);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);

    int j;
    for (i = 0; i < n; i++) {
        int c = 0;
        for (j = i; j < n; j++) {
            if (trie[c][s[j]-'a'] == 0) trie[c][s[j]-'a'] = ++num,pos[num] = mp(i,j);
            c = trie[c][s[j]-'a'];
        }
    }
    doDFS(0);
    int l = 0,r = order.size()-1;
    while (l < r) {
        int mm = (l+r+1) / 2;

        string ss;
        for (i = order[mm].first; i <= order[mm].second; i++) ss += s[i];
        memset(poss,0,sizeof(poss));
        for (i = 0; i < n; i++) {
            poss[i] = n+1;
            for (j = i; j < n; j++) {
                if (s[j] < ss[j-i]) break;
                else if (s[j] > ss[j-i]) {
                    poss[i] = j+1;
                    break;
                }
                else if (j-i+1 == ss.size()) {
                    poss[i] = j+1;
                    break;
                }
            }
        }
        memset(dp,0,sizeof(dp));
        for (i = 0; i < n; i++) {
            if (poss[i] <= n) dp[1][i] = 1;
            else dp[1][i] = 0;
        }
        for (i = 2; i <= m; i++) {
            for (j = n-1; j >= 0; j--) suff[j] = min(suff[j+1] + dp[i-1][j],(LLI) 1.5e18);
            for (j = n-1; j >= 0; j--) dp[i][j] = suff[poss[j]];
        }
        if (dp[m][0] >= k) l = mm;
        else r = mm-1;
    }
    string ss;
    for (i = order[l].first; i <= order[l].second; i++) ss += s[i];
    cout << ss << endl;

    return 0;
}