#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;
const int max_d = 1e6 + 100;

int a, b;
int x[max_n], n;
int d[max_d], e[max_d];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x, x + n);
    cin >> a >> b;
    for (int i = 0; i <= a - b; ++i)
        d[i] = 2;
    for (int i = 0; i < n; ++i)
        if (i == 0 || x[i] != x[i - 1]) {
            for (int j = b - (b % x[i]); j <= a; j += x[i])
                if (j >= b) {
                    d[j - b] = max(d[j - b], x[i]);
                }
        }
    int right = 0;
    for (int i = 0; i <= a - b; ++i)
        if (min(i + d[i] - 1, a - b) > right) {
            for (int j = right + 1; j <= min(i + d[i] - 1, a - b); ++j)
                e[j] = i;
            right = min(i + d[i] - 1, a - b);
        }
    int ans = 0;
    int pos = a - b;
    while (pos != 0) {
        pos = e[pos];
        ++ans;
    }
    cout << ans << endl;
    return 0;
}