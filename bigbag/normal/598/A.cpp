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

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans, n;
        cin >> n;
        ans = (n * (n + 1)) / 2;
        for (int i = 1; i <= n; i *= 2) {
            ans -= 2 * i;
        }
        cout << ans << endl;
    }
    return 0;
}