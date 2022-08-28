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

char s[100001];
vpii key;
bool comp(pii a,pii b) {
    if (a.second == b.second) return a.first > b.first;
    else return a.second < b.second;
}
int ll[100000][26],rr[100000][26],pp[26];
int pre[26][100000];
int dp[100000][26],dp2[100000][26];
int findAns(int l,int r,int ls,int rs) {
    if (l > r) return 0;
    if (ls && (dp[r][s[l-1]-'a'] != -1)) return dp[r][s[l-1]-'a'];
    if (rs && (dp2[l][s[r+1]-'a'] != -1)) return dp2[l][s[r+1]-'a'];
    int i;
    UI seen = 0;
    for (i = 0; i < 26; i++) {
        if (((i == s[l]-'a') ? l:rr[l][i]) <= r) {
            int rrr = (i == s[l]-'a') ? l:rr[l][i];
            int lll = (i == s[r]-'a') ? r:ll[r][i];
            int x = findAns(l,rrr-1,ls,1)^findAns(lll+1,r,1,rs);
            if (lll != rrr) x ^= pre[i][lll]^pre[i][rr[rrr][i]-1];
            seen |= (1U << x);
        }
    }
    int ans = 0;
    while (seen & (1U << ans)) ans++;
    if (ls) dp[r][s[l-1]-'a'] = ans;
    if (rs) dp2[l][s[r+1]-'a'] = ans;
    return ans;
}
int main() {
    int i;
    int m,l,r;
    scanf("%s %d",s,&m);

    int j,n = strlen(s);
    fill(pp,pp+26,-1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) ll[i][j] = pp[j];
        pp[s[i]-'a'] = i;
    }
    fill(pp,pp+26,n);
    for (i = n-1; i >= 0; i--) {
        for (j = 0; j < 26; j++) rr[i][j] = pp[j];
        pp[s[i]-'a'] = i;
    }
    for (i = 0; i < n; i++) {
        if ((rr[i][s[i]-'a'] > i+1) && (rr[i][s[i]-'a'] < n)) key.pb(mp(i+1,rr[i][s[i]-'a']-1));
    }
    sort(key.begin(),key.end(),comp);
    int x = 0;
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));
    for (i = 0; i < key.size(); i++) {
        while (x < key[i].second+1) {
            for (j = 0; j < 26; j++) pre[j][x+1] = pre[j][x];
            x++;
        }
        pre[s[key[i].second+1]-'a'][key[i].second+1] ^= findAns(key[i].first,key[i].second,1,1);
    }
    while (x < n-1) {
        for (j = 0; j < 26; j++) pre[j][x+1] = pre[j][x];
        x++;
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d",&l,&r);
        l--,r--;
        printf((findAns(l,r,0,0) > 0) ? "Alice\n":"Bob\n");
    }

    return 0;
}