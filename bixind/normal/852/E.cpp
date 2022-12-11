#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

const ll mod = 1e9 + 7;

vector<vector<int> > tr;
vector<ll> ch, nch, chsum, nchsum;

ll pw(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void dfs(int v, int pr) {
    if (tr[v].size() == 1 && tr[v][0] == pr) {
        chsum[v] = 1;
        nchsum[v] = 0;
        ch[v] = (chsum[v] + nchsum[v]) % mod;
        nch[v] = ch[v];
        return;
    }
    chsum[v] = 1;
    nchsum[v] = 1;
    for (int i = 0; i < tr[v].size(); ++i) {
        if (tr[v][i] != pr) {
            dfs(tr[v][i], v);
            chsum[v] = (chsum[v] * ch[tr[v][i]]) % mod;
            nchsum[v] = (nchsum[v] * nch[tr[v][i]]) % mod;
        }
    }
    ch[v] = (chsum[v] + nchsum[v]) % mod;
    nch[v] = ch[v];
}

ll ans;

void dfs1(int v, int pr, ll pval) {
//    cout << v << ' ' << pval << ' ' << ans << endl;
    if (nchsum[v] == 0)
        ans = (ans + chsum[v] * pval * 2) % mod;
    else
        ans = (ans + chsum[v] * pval + nchsum[v] * pval) % mod;
    for (int i = 0; i < tr[v].size(); ++i) {
        if (tr[v][i] != pr) {
            ll nval = ((chsum[v] * pval) % mod * pw(ch[tr[v][i]], mod - 2) +
                    (nchsum[v] * pval) % mod * pw(nch[tr[v][i]], mod - 2)) % mod;
            if (tr[v].size() == 1)
                nval = 1;
            dfs1(tr[v][i], v, nval);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    tr.resize(n);
    ch.resize(n);
    nch.resize(n);
    nchsum.resize(n);
    chsum.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    ans = 0;
    dfs(0, -1);
//    for (int i = 0; i < n; ++i) {
//        cout << ch[i] << ' ';
//    }
//    cout << endl;
    dfs1(0, -1, 1);
    cout << ans << endl;
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}