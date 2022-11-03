#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> l(n);
    vector<int> r(n);
    
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty()) {
            int id = s.top();
            if (a[id] > a[i]) {
                r[id] = i - 1;
                s.pop();
                continue;
            } else {
                break;
            }
        }
        s.push(i);
    }
    while (!s.empty()) {
        int id = s.top();
        s.pop();
        r[id] = n - 1;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty()) {
            int id = s.top();
            if (a[id] > a[i]) {
                l[id] = i + 1;
                s.pop();
                continue;
            } else {
                break;
            }
        }
        s.push(i);
    }
    while (!s.empty()) {
        int id = s.top();
        s.pop();
        l[id] = 0;
    }
    
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int mx = r[i] - l[i] + 1;
        ans[mx] = max(ans[mx], a[i]);
    }
    for (int i = n - 1; i > 0; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}