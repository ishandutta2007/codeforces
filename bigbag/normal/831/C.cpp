#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2222;
const long long inf = 1011011011022022022LL;

int n, m, a[max_n], b[max_n];

bool ok(int x) {
    set<int> all;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        all.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        if (!all.count(b[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    set<int> ans;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (ok(b[0] - sum)) {
            ans.insert(b[0] - sum);
        }
    }
    cout << ans.size() << endl;
    return 0;
}