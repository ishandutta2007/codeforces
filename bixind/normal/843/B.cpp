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

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

const int MAXN = 100010;


void solve() {
    int n, start, x;
    cin >> n >> start >> x;
    int cnt = min(n, 990);
    int bans = -1, bpos = start;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < cnt; ++i) {
        cout << "? " << v[i] << endl;
        cout.flush();
        int tans, tpos;
        cin >> tans >> tpos;
        if (tans == -1 && tpos == -1) {
            return;
        }
        if (tans == x) {
            cout << "! " << tans << endl;
            cout.flush();
            return;
        }
        if (tans > bans && tans <= x) {
            bans = tans;
            bpos = tpos;
        }
    }
    while(1) {
        if (bpos == -1) {
            cout << "! " << -1 << endl;
            cout.flush();
            return;
        }
        cout << "? " << bpos << endl;
        cout.flush();
        int tpos, tans;
        cin >> tans >> tpos;
        if (tans == -1 && tpos == -1) {
            return;
        }
        if (tans >= x) {
            cout << "! " << tans << endl;
            cout.flush();
            return;
        }
        bpos = tpos;
    }
}

int main() {
    cout.precision(20);
    cin.tie(0);
    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}