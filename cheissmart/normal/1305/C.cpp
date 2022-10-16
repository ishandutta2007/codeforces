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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[200005], cnt[1002];

int qpow(int a, int b, int m) {
	if(b == 0) return 1;
	int t = qpow(a, b/2, m);
	t = t * t % m;
	if(b&1) return t * a % m;
	else return t;
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int ans = 1;
	for(int i=0;i<m;i++) {
		memset(cnt, 0, sizeof cnt);
		int cur = 0;
		for(int j=0;j<n;j++) {
			cur += cnt[(a[j]%m-i+m)%m];
			cnt[a[j]%m]++;
		}
		ans = ans * qpow(i, cur, m) % m;
	}
	cout << ans << endl;

}