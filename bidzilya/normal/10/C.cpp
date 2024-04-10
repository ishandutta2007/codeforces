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

ll cnt[10];
ll ans = 0;
int n;

int digit_root(int x) {
    if (x <= 9)
        return x;
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return digit_root(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        ++cnt[digit_root(i)];
    for (int da = 0; da < 10; ++da)
        for (int db = 0; db < 10; ++db)
            ans += cnt[da] * cnt[db] * cnt[digit_root(da * db)];
    for (int a = 1; a <= n; ++a)
        ans -= n / a;
    cout << ans << endl;
    return 0;
}