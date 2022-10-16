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

const int INF = 1e9 + 7, MAGIC = 500;

int a[200005], p[200005], cnt[100200005], nxt[200005];

signed main()
{
	IO_OP;
	string s;
	cin >> s;
	int n = s.size();
	for(int i=1;i<=n;i++)
		a[i] = s[i-1] - '0';
	for(int i=1;i<=n;i++)
		p[i] = a[i] + p[i-1];
	nxt[n] = n+1;
	for(int i=n-1;i>=0;i--) {
		if(a[i+1] == 1) nxt[i] = i + 1;
		else nxt[i] = nxt[i+1];
	}
	ll ans = 0;
	for(int k=1;k<=MAGIC;k++) {
		vi v;
		for(int i=0;i<=n;i++) {
			cnt[k*p[i]-i+n]++;
			v.PB(k*p[i]-i+n);
		}
		for(int i:v) {
			ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
			cnt[i] = 0;
		}
	}
	for(int i=0;i<=n;i++) {
		int j = nxt[i];
		while(j <= n) {
			int c = p[j] - p[i];
			int l = max(j - i, MAGIC * c + 1), r = nxt[j] - 1 - i;
			if(l <= r) ans += r / c - (l - 1) / c;
			if((p[j] - p[i]) * MAGIC > n) break;
			j = nxt[j];
		}	
	}
	cout << ans << endl;
}