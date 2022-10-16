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

int a[300005];

int32_t main()
{
	IO_OP;
	
	int n, m, g = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(i) {
			g = __gcd(g, a[i] - a[i-1]);
		}
	}
	for(int i=1;i<=m;i++) {
		int p;
		cin >> p;
		if(g % p == 0) {
			cout << "YES" << endl;
			cout << a[0] << " " << i << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}