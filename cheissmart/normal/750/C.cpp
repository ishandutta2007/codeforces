#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;
	
	int mn = INF, mx = -INF, n, cur = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int c, d;
		cin >> c >> d;
		if(d == 1) {
			mn = min(mn, cur);
		} else {
			mx = max(mx, cur);
		}
		cur += c;
	}
	if(mx == -INF) {
		cout << "Infinity" << endl;
		return 0;
	} 
	if(mn <= mx) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << 1899-mx+cur << endl;
}