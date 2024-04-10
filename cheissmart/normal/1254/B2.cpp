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

int a[1000006], n;

int go(int p) {
	int req = 0;
	for(int i=0;i<n-1;i++)
		req += min(a[i] % p, p - a[i] % p);
	return req;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(i) a[i] += a[i-1];
	}
	int cnt = a[n-1];
	if(cnt == 1) {
		cout << -1 << endl;
		return 0;
	}
	int ans = INF;
	for(int i=2;i*i<=cnt;i++) {
		if(cnt % i) continue;
		while(cnt % i == 0) cnt /= i;
		ans = min(ans, go(i));
	}
	if(cnt != 1) ans = min(ans, go(cnt));
	cout << ans << endl;

	
}