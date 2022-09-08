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

int n;
long long a, b, L, t, m;

long long fun(long long poz) {
    return a + b * (poz - 1);
}

bool ok(int l, int r) {
    if (fun(r) > t) {
        return false;
    }
    long long st = fun(l), len = r - l + 1;
    long long x = st * (r - l + 1) + b * len * (len - 1) / 2;
    //cout << l << " " << r << " " << st << "  " << x << endl;
    return x <= m * t;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> n;
    while (n--) {
        cin >> L >> t >> m;
        if (fun(L) > t) {
            cout << -1 << endl;
        } else {
            int l = L, r = 1000111;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (ok(L, mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cout << l << endl;
        }
    }
    return 0;
}