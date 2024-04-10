#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, a[12];
    cin >> k;
    for(int i = 0; i < 12; ++i) cin >> a[i];
    int sum = 0, cnt = 0;
    sort(a, a+12);
    for(int i = 11; i >= 0; --i) {
        if(sum >= k) break;
        sum += a[i]; cnt++;
    }
    if(sum >= k) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}