#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    int sum = 0;
    vector <int> x(a), y(b), z(c);
    for(int i = 0; i < a; i++) {
        cin >> x[i];
        sum += x[i];
    }
    for(int i = 0; i < b; i++) {
        cin >> y[i];
        sum += y[i];
    }
    for(int i = 0; i < c; i++) {
        cin >> z[i];
        sum += z[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    vector <int> p;
    p.push_back(*min_element(x.begin(), x.end()) + *min_element(y.begin(), y.end()));
    p.push_back(*min_element(x.begin(), x.end()) + *min_element(z.begin(), z.end()));
    p.push_back(*min_element(z.begin(), z.end()) + *min_element(y.begin(), y.end()));
    p.push_back(accumulate(x.begin(), x.end(), 0ll));
    p.push_back(accumulate(y.begin(), y.end(), 0ll));
    p.push_back(accumulate(z.begin(), z.end(), 0ll));
    sort(p.begin(), p.end());
    cout << sum - 2*p[0];
    return 0;
}