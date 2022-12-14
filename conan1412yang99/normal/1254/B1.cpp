#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e18 + 7;

int a[100005], n;

int go(int p) {
	vi v;
	int ans = 0;
	for(int i=0;i<n;i++) {
		if(a[i]) v.PB(i);
		if((int)v.size() == p) {
			for(int j=0;j<p/2;j++) ans += v[p-j-1] - v[j];
			v.clear();
		}
	}
	return ans;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	int cnt = 0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		cnt += a[i];
	}
	if(cnt == 1) {
		cout << -1 << endl;
		return 0;
	}
	int ans = go(cnt);
	for(int i=2;i*i<=cnt;i++)
		if(cnt % i == 0)
			ans = min(ans, min(go(i), go(cnt/i)));
	cout << ans << endl;

	
}