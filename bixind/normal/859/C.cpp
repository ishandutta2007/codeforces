#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>
#include <list>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;
const ll mod = 1000000007;

ll d[100][2];

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll> sm(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        sm[i] = sm[i + 1] + v[i];
    }
    d[n][0] = 0;
    d[n][1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int h = 0; h <= 1; ++h) {
            d[i][h] = max(d[i + 1][h], v[i] + sm[i + 1] - d[i + 1][h^1]);
        }
    }
    cout << sm[0] - d[0][0] << ' ' << d[0][0] << endl;
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();

    return 0;
}