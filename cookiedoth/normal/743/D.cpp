#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mx = 300000;
ll n, good[mx], p[mx], sum[mx], max_sum[mx], ans = -1e18;
vector<ll> chld[mx], r[mx], srt;

void build_tree(ll v) {
    ll v1;
    for (ll i = 0; i < r[v].size(); ++i) {
        v1 = r[v][i];
        if (v1 != p[v]) {
            chld[v].push_back(v1);
            p[v1] = v;
            build_tree(v1);
        }
    }
}

void count_sum(ll v) {
    ll a = good[v], v1;
    for (ll i = 0; i < chld[v].size(); ++i) {
        v1 = chld[v][i];
        count_sum(v1);
        a += sum[v1];
    }
    sum[v] = a;
}

void count_max_sum(ll v) {
    ll a = sum[v], v1;
    for (ll i = 0; i < chld[v].size(); ++i) {
        v1 = chld[v][i];
        count_max_sum(v1);
        a = max(a, max_sum[v1]);
    }
    max_sum[v] = a;
}

int main()
{
    ll u, v, v1, s;
    cin >> n;
    for (ll i = 0; i < n; ++i) cin >> good[i];
    for (ll i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        r[u - 1].push_back(v - 1);
        r[v - 1].push_back(u - 1);
        p[i] = -1;
    }
    build_tree(0);
    count_sum(0);
    count_max_sum(0);
    for (ll i = 0; i < n; ++i) {
        srt.clear();
        if (chld[i].size() >= 2) {
            for (ll j = 0; j < chld[i].size(); ++j) {
                v1 = chld[i][j];
                srt.push_back(max_sum[v1]);
            }
            sort(srt.begin(), srt.end());
            s = srt.size();
            ans = max(ans, srt[s - 1] + srt[s - 2]);
        }
    }
    if (ans > -1e18) {
        cout << ans;
    }
    else {
        cout << "Impossible";
    }
    return 0;
}