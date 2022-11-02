// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define mp make_pair
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 100900
#define inf 0x3f3f3f3f

int t, n;
string x, y;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        cin >> x >> y;
        int ok = 0;
        for (int i = 0; i < x.size(); ++ i) if (x[i] > y[i]) ok = 1;
        if (ok == 1) cout << -1 << "\n";
        else {
            int ans = 0;
            while (x != y) {
                PII sml = mp(200, 200);
                for (int i = 0; i < x.size(); ++ i) if (x[i] < y[i]) {
                    sml = min(sml, mp(x[i] - 'a', y[i] - 'a'));
                }
                ans ++;
                for (int i = 0; i < x.size(); ++ i) if (x[i] < y[i]) {
                    if (x[i] - 'a' == sml.F) x[i] = sml.S + 'a';
                }
//                cout << x << endl;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}