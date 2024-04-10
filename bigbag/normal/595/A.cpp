#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1, inf = 1000000007;

int n, m, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (n--) {
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            ans += (x | y);
        }
    }
    cout << ans << endl;
    return 0;
}