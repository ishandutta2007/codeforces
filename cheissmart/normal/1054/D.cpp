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

const int INF = 1e9 + 7;

int a[200005];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i] ^= a[i-1];
	}
	map<int, int> m;
	for(int i=0;i<=n;i++)
		m[min(a[i], a[i]^((1<<k)-1))]++;
	int ans = n*(n+1)/2;
	for(pi p:m) {
		int x = p.S / 2, y = p.S - x;
		ans -= x*(x-1)/2 + y*(y-1)/2;
	}
	cout << ans << endl;
}