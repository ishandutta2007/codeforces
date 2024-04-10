#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    long long l = a[0], r = (a[0] + a[1] + a[2]) / 3, ans = l;

    while(l <= r) {
        long long m = (l + r) / 2;
        // cout << l << ' ' << m << ' ' << r << endl;
        bool suc = true;

        if(a[0] + a[1] < m) suc = false;

        if(suc) {l = m + 1; ans = m;}
        else r = m - 1;
    }
    cout << ans << endl;

    return 0;
}