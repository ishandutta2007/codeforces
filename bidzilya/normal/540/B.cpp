#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        x -= a[i];
    } 
    if (x < 0) {
        cout << -1 << endl;
        return 0;
    }
    int m = n / 2;
    for (int c1 = 0; c1 <= n - k; ++c1) {
        int xx = x - c1;
        if (xx < 0) {
            continue;
        }
        for (int med = y; med <= p; ++med) {
            
        }
    }
    for (int med = y; med <= p; ++med) {
        int ll = 0;
        int rr = 0;
        int cc = 0;
        for (int i = 0; i < k; ++i) {
            if (a[i] < med) {
                ++ll;
            } else if (a[i] > med) {
                ++rr;
            } else {
                ++cc;
            }
        }
        if (ll > m) {
            continue;
        }
        if (rr > m) {
            continue;
        }
        ll = m - ll;
        rr = m - rr;
        int xx = x;
        int c1 = 0;
        int cmed = 0;
        if (cc > 0) {
            --cc;
        } else {
            xx -= med;
            ++cmed;
        }
        if (rr >= cc) {
            xx -= (rr - cc) * med;
            cmed += (rr - cc);
            cc = 0;
        } else {
            cc -= rr;
        }
        ll -= cc;
        xx -= ll;
        c1 += ll;
        if (xx >= 0) {
            for (int i = 0; i < c1; ++i) {
                cout << 1 << " ";
            }
            for (int i = 0; i < cmed; ++i) {
                cout << med << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}