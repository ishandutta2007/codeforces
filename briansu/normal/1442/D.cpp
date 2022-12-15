#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<ll> arr[3005];
int n, k;
ll ans;

vector<pll> seg[4 * 3005];
void ins(int idx, int L, int R, int l, int r, const pll &p) {
    if (L >= r || R <= l)
        return;
    if (L <= l && R >= r)
        seg[idx].pb(p);
    else
        ins(idx<<1, L, R, l, (l+r)>>1, p), ins(idx<<1|1, L, R, (l+r)>>1, r, p);
}
void dfs(int idx, int l, int r, vector<ll> dp) {
    for (auto &[sz, val] : seg[idx])
        for (int i = k - sz; i >= 0; i--)
            dp[i + sz] = max(dp[i + sz], dp[i] + val);
    if (l == r - 1) {
        ll tt = 0; 
        for (int i = 0; i < k && i < SZ(arr[l]); i++)
            tt += arr[l][i], ans = max(ans, dp[k - i - 1] + tt);
    }
    else
        dfs(idx<<1, l, (l+r)>>1, dp), dfs(idx<<1|1, (l+r)>>1, r, dp);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[i].resize(t);
        for (int j = 0; j < t; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i++)
        if (SZ(arr[i]) <= k) {
            ll sum = 0;
            for (int x : arr[i])
                sum += x;
            ins(1, 0, i, 0, n, {SZ(arr[i]), sum});
            ins(1, i + 1, n, 0, n, {SZ(arr[i]), sum});
        }
    dfs(1, 0, n, vector<ll>(k + 1, 0));
    cout << ans << endl;
}