#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> a;
vector<ll> ans;
map<vector<int>, ll> res;
vector<ll> chain;
vector<vector<ll>> chaint;
void dfs(int r, int x, vector<ll> g) {
    if (r == 0) {
        ll v = 0;
        for (int i = 0; i < (1 << n); ++i)
            v += __builtin_parity(((1 << n) - 1) ^ i) ? -g[i] : g[i];
        res[a] = v;
        return;
    }
    for (int i = x; i <= r; ++i) {
        if (i != r && 2 * i > r)
            continue;
        a.push_back(i);
        auto g0 = g;
        for (int j = 0; j < (1 << n); ++j)
            g0[j] *= chaint[i][j];
        dfs(r - i, i, g0);
        a.pop_back();
    }
}
void f(vector<ll> &v) {
    for (int i = 1; i < (1 << n); i *= 2)
        for (int j = 0; j < (1 << n); j += 2 * i)
            for (int k = 0; k < i; ++k)
                v[i + j + k] += v[j + k];
}
void h(vector<ll> &v) {
    for (int i = 1; i < (1 << n); i *= 2)
        for (int j = 0; j < (1 << n); j += 2 * i)
            for (int k = 0; k < i; ++k)
                v[j + k] -= v[i + j + k];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }
    chaint.assign(1 << n, vector<ll>(n));
    chain.resize(1 << n);
    for (int s = 1; s < (1 << n); ++s) {
        if ((s & -s) == s) {
            chaint[s][__builtin_ctz(s)] = 1;
        } else {
            for (int v = 0; v < n; ++v)
                if (s >> v & 1)
                    for (int u = 0; u < n; ++u)
                        if (g[u][v] && (s >> u & 1))
                            chaint[s][v] += chaint[s ^ 1 << v][u];
        }
        for (int i = 0; i < n; ++i)
            chain[s] += chaint[s][i];
    }
    chaint.assign(n + 1, vector<ll>(1 << n));
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < (1 << n); ++s)
            if (__builtin_popcount(s) == i)
                chaint[i][s] = chain[s];
        f(chaint[i]);
    }
    dfs(n, 1, vector<ll>(1 << n, 1));
    ans.resize(1 << n);
    for (int s = 0; s < (1 << (n - 1)); ++s) {
        vector<int> a;
        int l = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (~s >> i & 1) {
                a.push_back(i - l);
                l = i;
            }
        }
        a.push_back(n - 1 - l);
        sort(a.begin(), a.end());
        ans[s] = res[a];
    }
    --n;
    h(ans);
    for (int i = 0; i < (1 << n); ++i)
        cout << ans[i] << " \n"[i == (1 << n) - 1];
    return 0;
}