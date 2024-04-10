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

const int INF = 1e9 + 7;

map<int, int> m;

int32_t main()
{
	IO_OP;
	
	int n,p,k;
	cin >> n >> p >> k;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		int r = (t * t % p * t % p * t % p - k * t % p + p) % p;
		m[r]++;
	}
	int ans = 0;
	for(auto p:m)
		ans += p.S * (p.S - 1) / 2;
	cout << ans << endl;
	
}