#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        ++d[x]; ++d[y];
    }
    sort(d.begin(), d.end());
    if (d[1] == 1 && d[n-1] == 2) {
        cout << "bus topology" << endl;
        return;
    }
    if (d[0] == 2 && d[n-1] == 2) {
        cout << "ring topology" << endl;
        return;
    }
    if (d[n-2] == 1 && d[n-1] == n - 1) {
        cout << "star topology" << endl;
        return;
    }
    cout << "unknown topology" << endl;
}

int main() {
    solve();
    return 0;
}