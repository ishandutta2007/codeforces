#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

ll a[200005];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		a[i] += a[i-1];
	vector<ll> v, m(n), mi(n);
	for(int i=k;i<=n;i++)
		v.PB(a[i] - a[i-k]);
	m[0] = v[0];
	for(int i=1;i<v.size();i++) {
		if(v[i] > m[i-1]) {
			m[i] = v[i];
			mi[i] = i;
		} else {
			m[i] = m[i-1];
			mi[i] = mi[i-1];
		}
	}
	ll ans = -1, ans1, ans2;
	for(int i=k;i<v.size();i++) {
		if(v[i] + m[i-k] > ans) {
			ans = v[i] + m[i-k];
			ans1 = mi[i-k], ans2 = i;
		}
	}
	cout << ans1+1 << " " << ans2+1 << endl;
	
}