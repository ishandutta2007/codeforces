#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    auto det = [&](int i, int j, int k) {
        // 1 1 1
        // xi xj xk
        // yi yj yk
        long long ans = 0;
        ans += x[i] * y[j];
        ans += x[j] * y[k];
        ans += x[k] * y[i];
        ans -= x[j] * y[i];
        ans -= x[k] * y[j];
        ans -= x[i] * y[k];
        return ans;
    };

    int at = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
        if (x[i] < x[at] || x[i] == x[at] && y[i] < y[at])
            at = i;
    }

    vis[at] = true;
    vector<int> sol;
    sol.push_back(at);
    
    string s; cin >> s;
    for (int i = 0; i < n - 2; ++i) {
        int nxt = -1;
        for (int j = 0; j < n; ++j) {
            if (vis[j]) continue;
            if (nxt == -1) { nxt = j; continue; }
            long long now = det(at, nxt, j);
            if (now < 0 && s[i] == 'L') nxt = j;
            if (now > 0 && s[i] == 'R') nxt = j;
        }
        sol.push_back(nxt);
        vis[nxt] = 1;
        at = nxt;
    }

    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) 
            sol.push_back(i);
    }

    for (auto x : sol) 
        cout << x + 1 << " ";
    cout << endl;


    return 0;
}