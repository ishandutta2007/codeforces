// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 1010
#define inf 0x3f3f3f3f

int n, x[maxn], a[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    for (int i = 1; i <= n; ++ i) x[i] = x[i] * n + i, a[i] = x[i];
    sort(a + 1, a + 1 + n);
    
    map<int, int> cc;
    for (int i = 1; i <= n; ++ i) cc[x[i]] = i;
    
    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) cnt += a[i] == x[i];

    while (cnt != n) {
        for (int i = 2; i <= n; ++ i) {
            if (cc[a[i]] < cc[a[i - 1]]) {
                int v1 = cc[a[i]];
                int v2 = cc[a[i - 1]];
                ans.emplace_back(v1, v2);
                cnt -= x[v1] == a[v1];
                cnt -= x[v2] == a[v2];
                swap(x[v1], x[v2]);
                cnt += x[v1] == a[v1];
                cnt += x[v2] == a[v2];
                swap(cc[x[v1]], cc[x[v2]]);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto to: ans) cout << to.first << " " << to.second << "\n";
    return 0;
}