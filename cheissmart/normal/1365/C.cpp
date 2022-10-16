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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	map<int, int> cnt;
	vi pos(n);
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		pos[t - 1] = i;
	}	
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cnt[(i - pos[t - 1] + n) % n]++;
	}
	int mx = 0;
	for(pi p:cnt) mx = max(mx, p.S);
	cout << mx << endl;
	
}