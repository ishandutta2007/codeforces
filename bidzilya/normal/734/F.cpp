#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <cassert>
using namespace std;

const int BITS_COUNT = 32;

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

const int BAD = -1;

int n;

vector<int> a;
vector<int> b;
vector<int> c;

void Solve() {
    for (int i = 0; i < n; ++i) {
        c[i] += b[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += c[i];
    }
    if (sum % (2 * n) != 0) {
        cout << BAD << endl;
        return;
    }
    sum /= (2 * n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        if (c[i] < sum) {
            cout << BAD << endl;
            return;
        }
        a[i] = c[i] - sum;
        if (a[i] % n != 0) {
            cout << BAD << endl;
            return;
        }
        a[i] /= n;
    }
    vector<long long> rb(n, 0);
    for (int bit = 0; bit < BITS_COUNT; ++bit) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (GetBit(a[i], bit)) {
                ++count;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (GetBit(a[i], bit)) {
                rb[i] += 1LL * count * (1LL << bit);
                if (rb[i] > b[i]) {
                    cout << BAD << endl;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (rb[i] != b[i]) {
            cout << BAD << endl;
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
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