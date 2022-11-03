#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

const string YES = "YES";
const string NO = "NO";

int n, m;
vector<string> a;
vector<string> b;

void Solve() {
    int k = 0;
    set<string> sa;
    for (int i = 0; i < n; ++i) {
        sa.insert(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        if (sa.find(b[i]) != sa.end()) {
            ++k;
        }
    }
    n -= k;
    m -= k;
    const int mk = (k >> 1);
    const int nk = k - mk;
    n += nk;
    m += mk;

    if (n > m) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
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