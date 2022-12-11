#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int d = 0, cnt = 0;
    d = v[1] - v[0];
    cnt = 1;
    for (int i = 2; i < v.size(); ++i) {
        if (v[i] - v[i - 1] < d) {
            cnt = 1;
            d = v[i] - v[i - 1];
        } else {
            if (v[i] - v[i - 1] == d)
                ++cnt;
        }
    }
    cout << d << ' ' << cnt << endl;
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

}