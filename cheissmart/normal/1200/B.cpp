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

int a[102];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int g = max(a[i+1] - k, 0);
		if(a[i]+m < g) {
			cout << "NO" << endl;
			return;
		}
		m += a[i] - g;
	}
	cout << "YES" << endl;
}

int main()
{
	IO_OP;
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}