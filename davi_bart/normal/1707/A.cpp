#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int l = 0, r = N - 1;
    while (l < r) {
        int m = (l + r) / 2;
        int k = Q;
        for (int i = 0; i < N; i++) {
            if (i >= m && v[i] > k) k--;
        }
        if (k >= 0)
            r = m;
        else
            l = m + 1;
    }
    string ans(N, '0');
    for(int i=0;i<N;i++){
        if(v[i]<=Q || i>=l)ans[i]='1';
    }
    cout<<ans<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}