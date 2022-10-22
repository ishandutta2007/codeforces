//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,k,ans,all,tot;
int m[MAXN],c[MAXN];
int cnt[MAXN];
vector<int> v[MAXN];

signed main () {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	all = n;
	for(register int i = 1;i <= n; ++i) {
		cin >> m[i];
		cnt[m[i]]++;
	}
	sort(m + 1,m + n + 1);
	for(register int i = 1;i <= k; ++i)
		cin >> c[i];
	for(register int i = n,at = 1;i >= 1; --i) {
		if((i == n || m[i] != m[i + 1]) && c[m[i]] != c[m[i + 1]]) at = 1;
		while(v[at].size() >= c[m[i]]) at++;
		v[at].push_back(m[i]);
		tot = max(tot,at);
	}
	cout << tot << endl;
	for(register int i = 1;i <= tot; ++i) {
		int len = v[i].size();
		cout << len << ' ';
		for(register int j = 0;j < len; ++j)
			cout << v[i][j] << ' ';
		cout << endl;
	}
	return 0;
}