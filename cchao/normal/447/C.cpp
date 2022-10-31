#include <bits/stdc++.h>
using namespace std;

int a[100010], l[100010]={}, r[100010]={};

int main() {
    int n, ans = 1; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        l[i] = 1 + (a[i] > a[i-1] ? l[i-1] : 0);
        ans = max(ans, 1+l[i-1]);
    }
    for(int i = n; i >= 1; --i) {
        r[i] = 1 + (a[i] < a[i+1] ? r[i+1] : 0);
        ans = max(ans, 1+r[i+1]);
    }

    for(int i = 2; i <= n-1; ++i) 
        if(a[i+1] - a[i-1] >= 2)
            ans = max(ans, 1 + l[i-1] + r[i+1]);

    cout << ans << endl;
    return 0;
}