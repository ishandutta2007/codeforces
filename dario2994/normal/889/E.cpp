#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    vector<LL> a(n+2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) a[i+1] = min(a[i], a[i+1]);

    a[n+1] = 1;

    priority_queue<pair<LL,LL>> q;
    q.push({a[1], 0});
    for (int i = 1; i <= n; i++) {
        LL val = -1;
        while (!q.empty() and q.top().first >= a[i+1]) {
            auto p = q.top();
            q.pop();
            
            LL u = p.first / a[i+1];
            LL v = p.first % a[i+1];
            val = max(val, p.second + i * (u-1) * a[i+1]);
            if (v > 0) q.push({v, p.second + i * u * a[i+1]});
        }
        if (val != -1) q.push({a[i+1], val});
    }

    LL x = 0;
    while (!q.empty()) {
        x = max(x, q.top().second);
        q.pop();
    }
    cout << x << "\n";   
}