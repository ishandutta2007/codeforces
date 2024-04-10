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

const int INF = 4e18 + 7, N = 1e5 + 7;

int a[N], b[N];
int n, k;

int f(int tt, int ai) {
	return -3*tt*tt+3*tt-1+ai;
}

int go(int m) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(int j=30;j>=0;j--) {
			int tt = cur + (1LL << j);
			if(f(tt, a[i]) >= m)
				cur = tt;
		}
		cur = min(cur, a[i]);
		sum += cur;
		b[i] = cur;
	}
	return sum;
}

signed main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int l = -INF, r = INF;
	while(l <= r) {
		int m = (l + r) / 2;
		if(go(m) < k) r = m - 1;
		else l = m + 1;
	}
	int m = r;
	int sum = go(m);
	int more = sum - k;
	for(int i = 0; i < n; i++) {
		if(b[i] == 0) continue;
		int tt = b[i];
		if(f(tt, a[i]) == m && more) {
			b[i]--;
			more--;
		}
	}
	if(more) cout << m << endl;
	assert(more == 0);
	for(int i = 0; i < n; i++) cout << b[i] << " ";
	cout << endl;
	
}