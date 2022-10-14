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

int cnt[100005];
vector<int> elist[100005];

void dfs(int u, int dp) {
    cnt[dp]++;
    for(int& v:elist[u]) dfs(v, dp+1);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    iter(i, 2, n+1) {
        int p; cin >> p;
        elist[p].pb(i);
    }
    dfs(1, 0);
    int ans = 0;
    rep(i, n+1) ans += cnt[i] % 2;
    cout << ans;
}