#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

ll ans[55];

bool ok(int n, ll a, ll b, ll m) {
	ans[0] = a;
	for (int i=0;i<n-2;i++) {
		a <<= 1;
		if (a > b) return false;
	}
	b -= a;
	b -= 1LL << (n-2);
	if(b < 0 || b > ((m-1)<<(n-2)))
		return false;
	int i = 1;
	for(int p=n-3;p>=0;p--,i++) {
		ll t = min(b >> p, m-1);
		ans[i] = t + 1;
		b -= t << p;
	}
	ll sum = ans[0];
	ans[n-1] = b + 1;
	for (int i=1;i<n;i++) {
		ans[i] += sum;
		sum += ans[i];
	}
	cout << n << " ";
	for (int i=0;i<n;i++)
		cout << ans[i] << " ";
	cout << endl;
	return true;
}

void solve() {
	ll a, b, m;
	cin >> a >> b >> m;
	if(a == b) {
		cout << 1 << " " << a << endl;
		return;
	}
	for(int i=2;i<=50;i++)
		if(ok(i, a, b, m))
			return;
	cout << -1 << endl;
}

int main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		solve();
	}
	
}