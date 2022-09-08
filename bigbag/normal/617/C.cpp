#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2222;
const long long inf = 1111111111111111111LL;

int n, x1, y1, x2, y2, x[max_n], y[max_n];
long long a[max_n], b[max_n];
vector<long long> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x1 >> y1 >> x2 >> y2;
    v.push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        long long q, w;
        q = x[i] - x1;
        w = y[i] - y1;
        a[i] = q * q + w * w;
        q = x[i] - x2;
        w = y[i] - y2;
        b[i] = q * q + w * w;
        v.push_back(a[i]);
    }
    long long ans = inf;
    for (int i = 0; i < v.size(); ++i) {
        long long q = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] > v[i]) {
                q = max(q, b[j]);
            }
        }
        ans = min(ans, v[i] + q);
    }
    cout << ans << endl;
    return 0;
}