#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 1<<20;

int a[N][21];
ll ans[N];

int32_t main()
{
	IO_OP;

	int n, w;
	cin >> n >> w;
	for(int t=0;t<n;t++) {
		int m;
		cin >> m;
		for(int i=0;i<m;i++) 
			cin >> a[i][0];
		for(int j=1;j<=20;j++)
			for(int i=0;i+(1<<(j-1))<m;i++)
				a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
		for(int i=0;i<w;i++) {
			int l = max(0, i-w+m);
			int r = min(m-1, i);
			int len = r - l + 1, lg = 32 - __builtin_clz(len) - 1;
			int res = max(a[l][lg], a[r-(1<<lg)+1][lg]);
			if(res < 0 && (i>=m || i<w-m))
				res = 0;
			ans[i] += res;
			if(l == 0 && r == m-1)// && i >= m && w >= 2 * m + 1)
				i = max(i, w - m - 1);
			ans[i+1] -= res;
		}
	}
	for(int i=1;i<w;i++)
		ans[i] += ans[i-1];
	for(int i=0;i<w;i++)
		cout << ans[i] << " \n"[i==w-1];
	
}