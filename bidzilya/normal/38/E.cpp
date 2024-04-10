#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int max_n = 3e3 + 100;
const ll INF = 1e18;

pair<ll, ll> p[max_n];
ll ans[max_n][max_n];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    ans[0][0] = p[0].second;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j)
            ans[i][j] = ans[i - 1][j] + p[i].first - p[j].first;
        ans[i][i] = ans[i - 1][0] + p[i].second;
        for (int j = i - 1; j > 0; --j)
            ans[i][i] = min(ans[i][i], ans[i - 1][j] + p[i].second);
    }
    ll mn = ans[n - 1][0];
    for (int i = 1; i < n; ++i)
        mn = min(mn, ans[n - 1][i]);
    cout << mn << endl;
    return 0;
}