#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        b[i] = abs(a[i] - a[i + 1]);
    }

    stack<int> s;
    vector<int> lf(n - 1);
    vector<int> rg(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        while (!s.empty() && b[s.top()] < b[i]) {
            int v = s.top();
            rg[v] = i - 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        int v = s.top();
        rg[v] = n - 2;
        s.pop();
    }
    for (int i = n - 2; i >= 0; --i) {
        while (!s.empty() && b[s.top()] <= b[i]) {
            int v = s.top();
            lf[v] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        int v = s.top();
        lf[v] = 0;
        s.pop();
    }
    for (int cq = 0; cq < q; ++cq) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        --r;
        long long ans = 0;
        for (int i = l; i <= r; ++i) {
            int clf = max(lf[i], l);
            int crg = min(rg[i], r);

            ans += 1LL * b[i] * (crg - i + 1) * (i - clf + 1);
        }
        cout << ans << endl;
    }

    return 0;
}