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

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int32_t main()
{
	IO_OP;
	
	int n, m, q;
	cin >> n >> m >> q;
	int g = gcd(n, m);
	int x = n / g, y = m / g;
	while(q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int n1, n2;
		if(a == 1)
			n1 = (b - 1) / x;
		else
			n1 = (b - 1) / y;
		if(c == 1)
			n2 = (d - 1) / x;
		else
			n2 = (d - 1) / y;
		if(n1 == n2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}

}