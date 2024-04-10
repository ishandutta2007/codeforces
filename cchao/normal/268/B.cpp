#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long ans = n;
    for(int i = 0; i < n; ++i) {
        ans += (i + 1) * (n - i - 1);
    }
    cout << ans << endl;
    return 0;
}