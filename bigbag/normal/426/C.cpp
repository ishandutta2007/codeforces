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

const int max_n = 222, inf = 1111111111;

int n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = -inf;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            vector<int> v1, v2;
            v1.clear();
            v2.clear();
            for (int i = l; i <= r; ++i) {
                v1.push_back(a[i]);
            }
            for (int i = 0; i < l; ++i) {
                v2.push_back(a[i]);
            }
            for (int i = r + 1; i < n; ++i) {
                v2.push_back(a[i]);
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            int poz1 = 0, poz2 = v2.size() - 1;
            while (poz1 < k && poz1 < v1.size() && poz1 >= 0 && poz2 >= 0 && poz2 <= v2.size() && v1[poz1] < v2[poz2]) {
                v1[poz1] = v2[poz2];
                ++poz1;
                --poz2;
            }
            int sum = 0;
            for (int i = 0; i < v1.size(); ++i) {
                sum += v1[i];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}