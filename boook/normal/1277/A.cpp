// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 
#define inf 0x3f3f3f3f


int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    vector<int> sol;
    for (int i = 1; i <= 9; ++ i) {
        long long now = i;
        while (now < (int)1e9 + 10) {
            sol.emplace_back(now);
            now = now * 10 + i;
        }
    }
    sort(sol.begin(), sol.end());
//    for (int i = 0; i < sol.size(); ++ i) cout << 
    int t;
    cin >> t;
    while (t --) {
        int now;
        cin >> now;
        auto tmp = upper_bound(sol.begin(), sol.end(), now);
        cout << (tmp - sol.begin()) << "\n";
    }
    return 0;
}