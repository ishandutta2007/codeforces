#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;

int f[300005];
vi m1[300005], m2[300005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		m1[x].PB(y);
		m2[y].PB(x);
	}
	f[0] = 1;
	for(int i=1;i<300005;i++)
		f[i] = f[i-1] * i % M;
	int ans = f[n], d1 = 1, d2 = 1, d3 = 1;
	for(int i=1;i<=n;i++)
		d1 = d1 * f[m1[i].size()] % M;
	for(int i=1;i<=n;i++)
		d2 = d2 * f[m2[i].size()] % M;
	ans = ((ans - d1 - d2) % M + M) % M;
	vi a, b;
	for(int i=1;i<=n;i++) {
		if(m1[i].size() == 0) continue;
		sort(ALL(m1[i]));
		map<int, int> m;
		for(int e:m1[i]) m[e]++;
		for(pi p:m)
			d3 = d3 * f[p.S] % M;
		a.PB(i);
		b.PB(m1[i][0]);
		b.PB(m1[i].back());
	}
	for(int i=0;i<a.size()-1;i++)
		if(a[i+1] < a[i])
			d3 = 0;
	for(int i=0;i<b.size()-1;i++)
		if(b[i+1] < b[i])
			d3 = 0;
	ans = (ans + d3) % M;
	cout << ans << endl;
}