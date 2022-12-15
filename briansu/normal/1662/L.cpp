#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

ll v, ti[200005], pl[200005];
int dp[200005];

void dq(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    dq(l, mid);
    vector<int> idx(r - l + 1);
    iota(ALL(idx), l);
    sort(ALL(idx), [&](int a, int b) {
        return pl[a] < pl[b]; 
    });
    map<ll, int> mp;
    for (int i : idx) {
        if (i <= mid) {
            auto p = mp.upper_bound(pl[i] - v * ti[i]);
            if (p != mp.end() && p->Y >= dp[i])
                continue;
            while (p != mp.begin() && prev(p)->Y <= dp[i])
                mp.erase(prev(p));
            mp.insert(make_pair(pl[i] - v * ti[i], dp[i]));
        }
        else {
            auto p = mp.lower_bound(pl[i] - v * ti[i]);
            if (p != mp.end())
                dp[i] = max(dp[i], p->Y + 1);
        }
    }
    reverse(ALL(idx)), mp.clear();
    for (int i : idx) {
        if (i <= mid) {
            auto p = mp.lower_bound(pl[i] + v * ti[i]);
            if (p != mp.begin() && prev(p)->Y >= dp[i])
                continue;
            if (p != mp.end() && p->X == pl[i] + v * ti[i] && p->Y >= dp[i])
                continue;
            while (p != mp.end() && p->Y <= dp[i])
                p = mp.erase(p);
            mp.insert(make_pair(pl[i] + v * ti[i], dp[i]));
        }
        else {
            auto p = mp.upper_bound(pl[i] + v * ti[i]);
            if (p != mp.begin())
                dp[i] = max(dp[i], prev(p)->Y + 1);
        }
    }
    dq(mid + 1, r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> v;
    const int INF = 1e9;
    fill(dp + 1, dp + n + 1, -INF);
    for (int i = 1; i <= n; ++i)
        cin >> ti[i];
    for (int i = 1; i <= n; ++i)
        cin >> pl[i];
    dq(0, n);
    cout << *max_element(dp, dp + n + 1) << "\n";
}