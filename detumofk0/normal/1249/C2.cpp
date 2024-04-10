#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    vector < long long > pw3(50, 1);
    for(int i = 1; i < pw3.size(); ++i) {
        pw3[i] = pw3[i - 1] * 3;
        if(pw3[i] > (long long)1e18) break;
    }

    int nTest; cin >> nTest;
    while(nTest--) {
        long long n; cin >> n;
        long long ans = 0;
        for(int i = pw3.size() - 1; i >= 0; --i) {
            long long cur = ans;
            for(int j = i - 1; j >= 0; --j) {
                cur += pw3[j];
            }
            if(cur >= n) continue;
            ans += pw3[i];
        }

        cout << ans << endl;
    }

    return 0;
}