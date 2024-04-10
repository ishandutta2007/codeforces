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

const int max_n = 111111, inf = 1111111111;

long long sum, n, r, avg, ans;
pair<long long, long long> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> r >> avg;
    avg *= n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
        sum += a[i].second;
        a[i].second = r - a[i].second;
    }
    if (sum >= avg) {
        cout << 0 << endl;
        return 0;
    }
    sort(a, a + n);
    avg -= sum;
    for (int i = 0; i < n; ++i) {
        if (avg <= a[i].second) {
            ans += avg * a[i].first;
            break;
        }
        ans += a[i].second * a[i].first;
        avg -= a[i].second;
    }
    cout << ans << endl;
    return 0;
}