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

int a[55], b[55];

int main()
{
	IO_OP;
	int n, m, r, mn = INF, mx = -INF;
	cin >> n >> m >> r;
	for(int i=1;i<=n;i++) {
		int a;
		cin >> a;
		mn = min(a, mn);
	}
	
	for(int i=1;i<=m;i++) {
		int a;
		cin >> a;
		mx = max(a, mx);
	}
	if(mn > mx) {
		cout << r << endl;
	} else {
		int d = r / mn;
		r %= mn;
		r += d * mx;
		cout << r << endl;
 	}
}