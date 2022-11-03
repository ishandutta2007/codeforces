#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

long long n;
int q;
vector<long long> ps;

long long Get(long long n, long long p) {
    assert(1 <= p && p <= n);
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return p;
    }
    const auto n2 = (n >> 1);
    if (n & 1) {
        if (p & 1) {
            return (p >> 1) + 1;
        }
        p >>= 1;
        if (p == 1) {
            return (n - n2) + Get(n2, n2);
        }
        return (n - n2) + Get(n2, p - 1);
    } else {
        if (p & 1) {
            return (p >> 1) + 1;
        }
        p >>= 1;
        return (n - n2) + Get(n2, p);
    }
}

void Solve() {
    for (int i = 0; i < q; ++i) {
        cout << Get(n, ps[i]) << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n >> q)) {
        return false;
    }
    ps.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> ps[i];
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