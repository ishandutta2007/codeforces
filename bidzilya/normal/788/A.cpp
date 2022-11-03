#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long INF = 1e18;

int n;
vector<long long> a;
vector<long long> sum;
vector<long long> mx, mn;

void Solve() {
    for (int i = 0; i + 1 < n; ++i) {
        a[i] = abs(a[i] - a[i + 1]);
        if (i & 1) {
            a[i] *= -1;
        }
    }
    --n;
    a.resize(n);

    sum.resize(n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    mx.resize(n);
    mn.resize(n);

    mx[n - 1] = mn[n - 1] = sum[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mx[i] = max(mx[i + 1], sum[i]);
        mn[i] = min(mn[i + 1], sum[i]);
    }

    long long result = -INF;
    for (int i = 0; i < n; ++i) {
        long long prev = (i == 0 ? 0 : sum[i - 1]);
        long long cur = ((i & 1) ? mn[i] : mx[i]);
        cur -= prev;
        if (i & 1) {
            cur *= -1;
        }
        result = max(result, cur);
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return true;
}

int main() {
    // freopen("input2.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}