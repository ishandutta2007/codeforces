#include<bits/stdc++.h>
#define pll pair<ll ,ll>
#define maxn 0x3f3f3f3f;
#define endl '\n'
#define lazy ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
 
typedef long long  ll;
const ll N = 2e5 + 7;
const ll M = 1e5 + 7;
const ll mod = 998244353;
ll t, n, l[N], r[N], ans, cnt[N];
vector<ll> edge[N];
 
void init() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
        cnt[i] = 0;
    }
}
 
void dfs(ll x) {
    for (auto i : edge[x]) {
        dfs(i);
        cnt[x] += cnt[i];
    }
    if (cnt[x] < l[x]) {
        ans++;
        cnt[x] = r[x];
    }
    cnt[x] = min(cnt[x], r[x]);
}
 
int main() {
    lazy;
    cin >> t;
    while (t--) {
        init();
        cin >> n;
        for (int i = 2; i <= n; i++) {
            ll a;
            cin >> a;
            edge[a].push_back(i);
        }
        for (int i = 1; i <= n; i++)cin >> l[i] >> r[i];
        dfs(1);
        cout << ans << endl;
    }
}