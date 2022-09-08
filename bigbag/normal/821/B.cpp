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

const int max_n = 1, inf = 1011111111;

int m, b;
long long ans;

long long sum(long long r) {
    return (r * (r + 1)) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> m >> b;
    for (int x = 0; ; ++x) {
        int h = b - (x + m - 1) / m;
        if (h < 0) {
            break;
        }
        long long res = 1LL * (h + 1) * sum(x) + 1LL * (x + 1) * sum(h);
        ans = max(ans, res);
        //cout << x << " " << h << " " << res << endl;
    }
    cout << ans << endl;
    return 0;
}