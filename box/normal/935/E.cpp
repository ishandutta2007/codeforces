// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

bool lf[10004];
pii dp[10004][105];
int lc[10004], rc[10004], nx;
string s;

#define plus MY_FUCKING_PLUS
#define minus MY_FUCKING_MINUS

function<pii(pii,pii)> plus = [](pii a, pii b)->pii{ return {a.fi+b.fi,a.se+b.se}; };
function<pii(pii,pii)> minus = [](pii a, pii b)->pii{ return {a.fi-b.se,a.se-b.fi}; };
pii best(pii a, pii b) { return {min(a.fi,b.fi),max(a.se,b.se)}; }

int build(int l, int r) {
    rep(i, 102) dp[nx][i] = {1<<20, -(1<<20)};
    if(r - l == 1) {
        lf[nx] = 1;
        dp[nx][0] = {s[l]-'0', s[l]-'0'};
        nx++;
        return nx - 1;
    }
    assert(s[l] == '(' && s[r-1] == ')');
    int cnt = 0;
    int thi = nx; nx++;
    iter(i, l, r) {
        if(s[i] == '(') cnt++;
        if(s[i] == ')') cnt--;
        if(s[i] == '?' && cnt == 1) {
            lc[thi] = build(l+1, i);
            rc[thi] = build(i+1, r-1);
            return thi;
        }
    } assert(0);
}

void Dp(int node) {
    if(lf[node]) return;
    Dp(lc[node]); Dp(rc[node]);
    for(int l=0; l<=101; l++)
        for(int r=0; l+r<=101; r++) {
            dp[node][l+r] = best(dp[node][l+r], minus(dp[lc[node]][l], dp[rc[node]][r]));
            dp[node][l+r+1] = best(dp[node][l+r+1], plus(dp[lc[node]][l], dp[rc[node]][r]));
        }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    int rt;
    
    int p, m; cin >> p >> m; 
    if(p > m) {
        swap(plus, minus);
        swap(p, m);

    }
    Dp(rt=build(0,s.size()));
    cout << dp[rt][p].se << endl;
}