#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int TT;
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> TT;
    for(int tt=1;tt<=TT;++tt) {
        cin >> n;
        int h = 32 - __builtin_clz(n-1);
        int ans = 0;
        for(int i=0;i<h;++i) {
            vector<int> a, b;
            for(int j=1;j<=n;j++) {
                if(j&(1<<i)) {
                    a.push_back(j);
                } else {
                    b.push_back(j);
                }
            }
            if(a.size() == 0 || b.size() == 0) continue;
            cout << a.size() << " " << b.size() << " ";
            for(auto& x : a) {
                cout << x << " ";
            }
            for(auto& x : b) {
                cout << x << " ";
            }
            cout << endl;
            int v;
            cin >> v;
            if(v == -1) return 0;
            ans = max(ans, v);
        }
        cout << "-1 " << ans << endl;
    }
    return 0;
}