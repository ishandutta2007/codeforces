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


using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    if ((n - 1) % k >= 2) {
        cout << 2 * ((n - 1) / k + 1) << endl;
    }
    if ((n - 1) % k == 1) {
        cout << 2 * ((n - 1) / k) + 1 << endl;
    }
    if ((n - 1) % k == 0) {
        cout << 2 * ((n - 1) / k) << endl;
    }
    int stlen = ((n - 1) / k);
    int cnt = 2;
    for (int i = 0; i < (n - 1) % k; ++i) {
        int prv = 1;
        for (int j = 0; j < stlen + 1; ++j) {
            cout << prv << ' ' << cnt << endl;
            prv = cnt;
            ++cnt;
        }
    }
    for (int i = 0; i < k - ((n - 1) % k); ++i) {
        int prv = 1;
        for (int j = 0; j < stlen; ++j) {
            cout << prv << " " << cnt << endl;
            prv = cnt;
            ++cnt;
        }
    }
}


int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}