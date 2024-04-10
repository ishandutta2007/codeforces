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

int a[1024];

int main()
{
	IO_OP;
	
	int n, m, q;
	string s, t;
	cin >> n >> m >> q >> s >> t;
	for(int i=0;i<n;i++) {
		if(i) a[i] += a[i-1];
		if(i <= n-m)
			a[i] += s.substr(i, m) == t;
	}
	while(q--) {
		int l, r, sl = 0, sr = 0;
		cin >> l >> r;
		l--, r--;
		if(r - l < m - 1) {
			cout << 0 << endl;
			continue;
		}
		if(l) sl = a[l-1];
		sr = a[r-m+1];
		cout << sr - sl << endl;
	}
	
}