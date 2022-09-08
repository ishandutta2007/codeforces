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

int n, m, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    int ans = 1e9;
    for (int i = 0; i < 1111; ++i) {
        int x = max(0, n - m * i);
        ans = min(ans, i * b + x * a);
    }
    cout << ans << endl;
    return 0;
}