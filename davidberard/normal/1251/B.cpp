#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int Q;
    cin >> Q;
    for (int qq=1; qq<=Q; ++qq) {
        int n;
        cin >> n;
        vector<string> s(n);
        vector<int> l(n);
        int z = 0, o = 0;
        int i = 0;
        for (auto& t : s) {
            cin >> t;
            for (auto& c : t) {
                if (c == '0') ++ z;
                if (c == '1') ++ o;
            }
            l[i++] = t.size();
            //cerr << " !! " << l[i-1] << endl;
        }
        for (int i=0; i<n; ++i) {
            if (l[i]%2 == 0) {
                while (z>1 && l[i]) {
                    z -= 2;
                    l[i] -=2;
                    //cerr << " " << i << " 00" << endl;
                }
                while (o>1 && l[i]) {
                    o -= 2;
                    l[i] -=2;
                    //cerr << " " << i << " 11" << endl;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (l[i]%2 == 1) {
                while (z && l[i]) {
                    z -= 1;
                    l[i] -=1;
                    //cerr << " " << i << " 0" << endl;
                }
                while (o && l[i]) {
                    o -= 1;
                    l[i] -=1;
                    //cerr << " " << i << " 1" << endl;
                }
            }
        }
        int ans = n;
        for (int i=0; i<n; ++i) {
            if (l[i]) --ans;
        }
        cout << ans << "\n";
    }
    return 0;
}