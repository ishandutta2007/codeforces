#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int id[N];
long long a[N];

vector<pair<long long, int> > factor(long long x) {
    vector<pair<long long, int> > ret;
    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        int j = 0;
        while (x % i == 0) j++, x /= i;
        ret.emplace_back(i, j);
    }
    if (x > 1) ret.emplace_back(x, 1);
    return ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
    long long n, b; cin >> n >> b;
    auto v = factor(b);
    long long ans = LLONG_MAX;
    for (auto t : v) {
        long long m = n, cur = 0;
        while (m) cur += m / t.first, m /= t.first;
        ans = min(ans, cur / t.second);
    }
    cout << ans << endl;
    return 0;
}