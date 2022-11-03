#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long INF = 1e18;

int n, l, r;
vector<long long> a;
vector<long long> b;
vector<int> p;

void Solve() {
    vector<pair<int, int>> order(n);
    for (int i = 0; i < n; ++i) {
        order[i].first = p[i];
        order[i].second = i;
    }
    sort(order.begin(), order.end());
    b.resize(n);
    long long value = -INF;
    for (int i = 0; i < n; ++i) {
        const int id = order[i].second;
        long long leftValue = l - a[id];
        long long rightValue = r - a[id];

        leftValue = max(leftValue, value + 1);

        if (leftValue <= rightValue) {
            value = leftValue;
            b[id] = leftValue + a[id];
        } else {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n >> l >> r)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}