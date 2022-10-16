#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M= 998244353;
int k;
int solve(int a[],int n)
{
	for(int i=0;i<n-1;i++)
		if(a[i] == a[i+1] && a[i] != -1)
			return 0;
	vi v({-1});
	for(int i=0;i<n;i++)
		if(a[i] != -1)
			v.PB(i);
	v.PB(n);
	int ans = 1;
	for(int i=1;i<v.size();i++) {
		int l = v[i-1] + 1;
		int r = v[i] - 1;
		if (l > r)
			continue;
		int c = 1, d = k - 2;
		if(l == 0 && r == n - 1) {
			for(int j=l;j<=r;j++)
				ans *= (k-(j>l)), ans %= M;
			continue;
		}
		if(l == 0 || r == n-1) {
			for(int j=l;j<=r;j++)
				ans *= (k-1), ans %= M;
			continue;
		}
		if(a[l-1] == a[r+1])
			c = 0, d = k - 1;
		for(int j=l+1;j<=r;j++) {
			tie(c,d) = make_pair(d * 1, (c * (k - 1) + d * (k - 2)) % M);
		}
		ans *= d;
		ans %= M;
	}
	return ans;
}
int a[100005], b[100005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		if(i & 1) cin >> b[i/2];
		else cin >> a[i/2];
	cout << solve(a,(n+1)/2)*solve(b,n/2)%M << endl;
}