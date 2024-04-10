#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int MAXN = 2001;
const long long inf = 2000000000000000000;
const double PI = 3.141592653589793;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[b[i].second] = a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}


int main() {
    cout.precision(20);
    cin.tie(0);
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}