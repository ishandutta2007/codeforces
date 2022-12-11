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

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

ll d[100010];

void solve() {
    d[0] = 0;
    d[1] = 0;
    for (ll i = 2; i < 3000; ++i) {
        d[i] = longinf;
        for (int j = 1; j < i; ++j) {
            d[i] = min(d[i], (i - j) * j + d[j] + d[i - j]);
        }
    }
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "a" << endl;
        return;
    }
    int j = 0;
    while (d[j] <= k)
        ++j;
    char c = 'a';
    while (k > 0) {
        while (d[j] > k)
            --j;
//        cout << j << ' ' << k < <endl;
        for (int i = 0; i < j; ++i) {
            cout << c;
        }
        k -= d[j];
        ++c;
    }
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}