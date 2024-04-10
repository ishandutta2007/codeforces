#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int pod = (1 << 18);
const int inf = 1e9;
const int N = 200005; 
 
int n;
int m;
vector <pair<int, int>> v;
int a, b;
int dp[N];
int wal[N];
 
int t[2 * pod];
 
void add(int x, int c) {
	x += pod;
	t[x] = max(t[x], c);
	x /= 2;
	while(x) {
		t[x] = max(t[2 * x], t[2 * x + 1]);
		x /= 2;
	}
}
 
int query(int l, int r) {
	r += 1;
	int ans = 0;
	for(l += pod, r += pod; l < r; l /= 2, r /= 2) {
		if(l & 1)
			ans = max(ans, t[l++]);
		if(r & 1)
			ans = max(ans, t[--r]);
	}
	return ans;
}
 
int main() {
	scanf("%d %d", &n, &m);
	FOR(i, n) {
		scanf("%d %d", &a, &b);
		v.pb(mp(a, b));
		add(max(0, a - b), a + b);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < N; ++i) {
		wal[i] = inf;
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int i = 0; i < N; ++i) {
		if(i > 0) {
			wal[i] = min(wal[i], wal[i - 1] + 1);
			dp[i] = min(wal[i], dp[i]);
		}
		for(auto it : v) {
			if(it.fi < i)
				continue;
			int dis = max(0, it.fi - it.se - i - 1);
			int right = it.fi + it.se + dis;
			wal[right] = min(wal[right], dp[i] + dis);
			right = query(0, right);
			wal[right] = min(wal[right], dp[i] + dis);
		}
	}
	int ans = inf;
	for(int i = m; i < N; ++i)
		ans = min(ans, dp[i]);
	printf("%d\n", ans);
		
	
	
		
		
	
	
	
	return 0;
}