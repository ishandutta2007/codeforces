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

const int max_n = 1111;

int n;
long long ans = 1111111111111111111LL, a[max_n], b[max_n];
vector<long long> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int x = 1; x <= 1000; ++x) {
        long long s1 = 0, s2 = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x && b[i] > x) {
                break;
            }
            ++k;
            if (a[i] <= x && b[i] <= x) {
                s1 = max(s1, max(a[i], b[i]));
                s2 += min(a[i], b[i]);
            } else {
                s1 = max(s1, min(a[i], b[i]));
                s2 += max(a[i], b[i]);
            }
        }
        if (k == n) {
            ans = min(ans, s1 * s2);
        }
    }
    cout << ans << endl;
    return 0;
}