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

const int INF = 1e9 + 7, M = 998244353;

signed main()
{
	IO_OP;
	
	int k, n;
	cin >> n >> k;
	vi v;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t > n - k) v.PB(i);
	}
	int ans = 0;
	for(int i=n;i>n-k;i--) ans += i;
	cout << ans << " ";
	ans = 1;
	for(int i=0;i<(int)v.size()-1;i++)
		ans = ans * (v[i+1]-v[i]) % M;
	cout << ans << endl;
	
}