#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 5e3 + 100;

int n;
int a[max_n];
pair<int, int> b[max_n];
ll d[max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        ll mn = d[b[0].second];
        for (int j = 0; j < n; ++j) {
            int id = b[j].second;
            mn = min(mn, d[id]);
            d[id] = mn + abs(a[i] - a[id]);
        }
    }
    ll ans = d[0];
    for (int i = 1; i < n; ++i)
        ans = min(ans, d[i]);
    cout << ans << endl;
    return 0;
}