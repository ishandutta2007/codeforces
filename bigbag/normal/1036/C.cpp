#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000LL * 1000000000LL;

vector<long long> v;

void rec(long long x, int cnt, int len) {
    if (cnt == 4) {
        return;
    }
    if (len == 18) {
        v.push_back(x);
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        rec(x * 10 + i, cnt + (i != 0), len + 1);
    }
}

int t;
long long l, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    rec(0, 0, 0);
    v.push_back(inf);
    sort(v.begin(), v.end());
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << (upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l)) << "\n";
    }
    return 0;
}