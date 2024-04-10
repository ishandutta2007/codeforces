#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<ll> vll;

const int INF = 1e9 + 7;

ll s[112345], f[100005], g[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> s[i];
	sort(s, s+n);
	n = unique(s, s+n) - s;
	vll v;
	v.PB(0);
	for(int i=0;i<n-1;i++)
		v.PB(s[i+1] - s[i]);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	f[0] = n;
	for(int i=0;i<n-1;i++)
		f[lower_bound(v.begin(), v.end(), s[i+1]-s[i])-v.begin()]--;
	for(int i=1;i<v.size();i++)
		f[i] += f[i-1];
	for(int i=1;i<v.size();i++) {
		g[i] = g[i-1] + f[i-1] * (v[i]-v[i-1]);
	}
	int q;
	cin >> q;
	while(q--) {
		ll l, r;
		cin >> l >> r;
		ll m = r - l;
		int pos = upper_bound(v.begin(), v.end(), m) - v.begin() - 1;
		ll ans = g[pos] + (m - v[pos] + 1) * f[pos];
		cout << ans << endl;
	}
}