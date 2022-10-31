#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a, b;
int x[120];
int y[120];

int main() {
    int ans = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int it1 = 0; it1 < 2; ++it1, swap(x[i], y[i])) {
                for (int it2 = 0; it2 < 2; ++it2, swap(x[j], y[j])) {
                    if (x[i] + x[j] <= a && max(y[i], y[j]) <= b)
                        ans = max(x[i] * y[i] + x[j] * y[j], ans);
                    if (x[i] + x[j] <= b && max(y[i], y[j]) <= a)
                        ans = max(x[i] * y[i] + x[j] * y[j], ans);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}