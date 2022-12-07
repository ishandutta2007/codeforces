#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<pair<int, int>> diff(n);
    for(int i = 0; i < n; i++) {
        diff[i] = {a[i] - b[i], i};
    }
    sort(diff.begin(), diff.end());
    int red_sum = 0;
    for(int i = 0; i < n; i++) {
        red_sum += a[i];
    }
    vector<int> x(n + 1); // max tastiness assuming i black and n - i red.
    x[0] = red_sum;
    for(int i = 1; i <= n; i++) {
        red_sum -= diff[i - 1].first;
        x[i] = red_sum;
    }
    // for(int i = 0; i <= n; i++) {
    //     cout << x[i] << ' ';
    // }
    int mx = max_element(x.begin(), x.end()) - x.begin(); // max tastiness comes on MX black and N - MX red.
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swap(a, b);
        int c = n;
        int x0, y0, g;
        bool pos = find_any_solution(a, b, c, x0, y0, g);
        if(!pos) {
            cout << -1 << '\n';
            continue;
        }
        // cout << x0 << ' ' << y0 << '\n';
        int k = (mx - a*x0)*g/(a*b);
        // int k = (1.0*mx/a - x0)*(g*1.0)/b;
        vector<pair<int, int>> v;
        for(int i = k - 1; i <= k + 1; i++) {
            v.push_back({x0 + i*b/g, y0 - i*a/g});
        }
        int ans = -1;
        for(auto i : v) {
            if(min(i.first, i.second) < 0) continue;
            // if(i.first + i.second != n) continue;
            // cout << i.first << ' ' << i.second << '\n';
            ans = max(ans, x[i.first * a]);
        }
        cout << ans << '\n';
    }

    return 0;
}