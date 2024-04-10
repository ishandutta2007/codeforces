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

int n, x, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        int j = x / i;
        if (i * j == x && j <= n) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}