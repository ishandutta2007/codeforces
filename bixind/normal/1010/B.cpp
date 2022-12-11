#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 1e9 + 7;

bool is_greater(int y) {
    cout << y << endl;
    cout.flush();
    int r;
    cin >> r;
    if (r == 0 || r == -2) {
        exit(0);
    }
    return r > 0;
}

void solve(istream &cin = cin, ostream &cout = cout) {
    int n, m;
    cin >> m >> n;
    vector<bool> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = !is_greater(1);
    }
    int l = 1, r = m + 1;
    int i = 0;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (is_greater(mid) ^ p[i % n]) {
            l = mid;
        } else {
            r = mid;
        }
        ++i;
    }
    is_greater(l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);

    solve();
    return 0;
}