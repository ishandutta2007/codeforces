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

const int max_n = 2222, inf = 1111111111;

int n, k, f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++f[x];
    }
    int ans = 0;
    for (int i = max_n - 1; i > 0;) {
        int sum = 0;
        while (i > 0 && f[i] == 0) {
            --i;
        }
        if (i == 0) {
            break;
        }
        int poz = i;
        while (i > 0 && sum < k) {
            if (sum + f[i] <= k) {
                sum += f[i];
                f[i] = 0;
            } else {
                int x = k - sum;
                sum = k;
                f[i] -= x;
                break;
            }
            --i;
        }
        ans += 2 * (poz - 1);
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}