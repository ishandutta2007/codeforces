#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 300000
#define F first
#define S second

int t, n, k, x[maxn][2];

vector<int> v1, v2;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	
    cin >> t;
    while (t --) {
        cin >> n >> k;
        v1.clear();
        v2.clear();
        for (int i = 1; i <= n; ++ i) cin >> x[i][0];
        for (int i = 1; i <= n; ++ i) cin >> x[i][1];
        for (int i = 1; i <= n; ++ i) {
            int in1 = x[i][0];
            int in2 = x[i][1];
            if (in2 == 1) v1.emplace_back(in1);
            if (in2 == 2) v2.emplace_back(in1);
        }
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end(), greater<int>());

        for (int i = 1; i < v1.size(); ++ i) v1[i] += v1[i - 1];
        for (int i = 1; i < v2.size(); ++ i) v2[i] += v2[i - 1];
        
        int all1 = v1.size() ? v1.back() : 0;
        int all2 = v2.size() ? v2.back() : 0;
        if (all1 + all2 < k) {
            cout << -1 << "\n";
            continue;
        }

//        for (auto to : v1) cout << to << " "; cout << "\n";
//        for (auto to : v2) cout << to << " "; cout << "\n";
        
        int ans = n * 10;
        for (int i = 0; i <= v1.size(); ++ i) {
            int has = i == 0 ? 0 : v1[i - 1];
            if (has >= k) ans = min(ans, i);
            else if (has + all2 >= k) {
                int need = k - has, now = -1;

                for (int j = 20; j >= 0; -- j) {
                    int to = now + (1 << j);
                    if (to < v2.size() && v2[to] < need) now = to;
                }
                now ++;
                ans = min(ans, i + (now + 1) * 2);
            }
        }
        cout << ans << "\n";
//        break;
    }
    return 0;
}