#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)

int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> a, b;
        rep(i, 2*n) {
            int x, y; cin >> x >> y;
            if(x == 0) a.push_back(abs(y));
            else b.push_back(abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double ans = 0;
        rep(i, n) {
            ans += sqrt(1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
        }
        cout << fixed << setprecision(20) << ans << endl;
    }
    return 0;
}