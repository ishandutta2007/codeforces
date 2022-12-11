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

void solve() {
    ll s;
    cin >> s;
    ll mn = 1000000000;
    for (ll i = 1; i <= 1000000; ++i) {
        mn = min(mn, i + (s/i + (s % i > 0)));
    }
    cout << mn * 2 << endl;
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();

    return 0;
}