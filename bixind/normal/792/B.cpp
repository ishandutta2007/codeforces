#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i;
    int pos = 0;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        pos = (pos + a) % v.size();
        cout << v[pos] + 1 << ' ';
        v.erase(v.begin() + pos);
        pos %= v.size();
    }
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

}