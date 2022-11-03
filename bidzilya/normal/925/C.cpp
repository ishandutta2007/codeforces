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

int GetBit(long long x, int bit) {
    return (x >> bit) & 1;
}

long long GetMask(int count) {
    return (1LL << count) - 1;
}

const int BITS_COUNT = 60;

int n;
vector<long long> b;

bool Solve(const vector<long long>& b, const int bitId, vector<long long>& r) {
    if (bitId == BITS_COUNT) {
        assert(b.size() == 0);
        return true;
    }
    vector<long long> ones;
    vector<long long> nb;
    for (const auto bi : b) {
        const long long x = bi - (bi & GetMask(bitId));
        if (x == (1LL << bitId)) {
            ones.push_back(bi);
        } else {
            nb.push_back(bi);
        }
    }
    vector<long long> nr;
    if (!Solve(nb, bitId + 1, nr)) {
        return false;
    }
    if (ones.empty()) {
        r = nr;
        return true;
    }
    r.reserve(b.size());
    r.push_back(ones[0]);
    int oneId = 1;
    for (int i = 0; i < (int) nr.size(); ++i) {
        r.push_back(nr[i]);
        if (GetBit(nr[i], bitId) == 1) {
            if (oneId < (int) ones.size()) {
                r.push_back(ones[oneId++]);
            }
        }
    }
    if (oneId != (int) ones.size()) {
        return false;
    }
    return true;
}

void Solve() {
    vector<long long> a;
    if (!Solve(b, 0, a)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (const auto x : a) {
            cout << x << " ";
        }
        cout << endl;
    }
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}