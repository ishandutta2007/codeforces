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

long long n, a[4], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a[1] >> a[2] >> a[3];
    ans = 1111111111111111LL;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            for (int k = 0; k <= 3; ++k) {
                if ((n + i + j + k) % 4 == 0) {
                    ans = min(ans, a[i] + a[j] + a[k]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}