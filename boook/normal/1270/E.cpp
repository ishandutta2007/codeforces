#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 2010
#define PII pair<int, int>


struct djs {
	int x[maxn];
	void init(){ for (int i = 0; i < maxn; ++ i) x[i] = i; }
	int Find(int a) { return a == x[a] ? a : x[a] = Find(x[a]); }
	void Union(int a , int b) { x[Find(a)] = Find(b); }
	int operator[](int a) { return Find(a); }
} ds;


int n, x[maxn][2];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    ds.init(); 
    vector<int> ans;
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i][0] >> x[i][1];

    int len = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = i + 1; j <= n; ++ j) {
            int v1 = x[i][0] - x[j][0];
            int v2 = x[i][1] - x[j][1];
            len = __gcd(len, v1 * v1 + v2 * v2);
        }
    }
   // cout << "len = " << len << endl;
    for (int i = 1; i <= n; ++ i) {
        for (int j = i + 1; j <= n; ++ j) {
            int v1 = x[i][0] - x[j][0];
            int v2 = x[i][1] - x[j][1];
            int dis = (v1 * v1 + v2 * v2) / len;
     //       cout << "i = " << i << " j = " << j << " dis = " << dis << endl;
            if (dis % 2 == 1) {
                ds.Union(i * 2 + 0, j * 2 + 1);
                ds.Union(i * 2 + 1, j * 2 + 0);
            }
            else {
                ds.Union(i * 2 + 0, j * 2 + 0);
                ds.Union(i * 2 + 1, j * 2 + 1);
            }
        
        }
    }
    for (int i = 1; i <= n; ++ i) if (ds[i * 2 + 0] == ds[1 * 2 + 0]) ans.push_back(i); 
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];

    return 0;
}