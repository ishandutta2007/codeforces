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

const int INF = 1e9 + 7;

int p[200*200+5];
int go(int n, int m) {
	if(n % m == m - 1) {
		return (n + 1) / m * p[m-1];
	} else {
		return n / m * p[m - 1] + p[n % m];
	}
}


signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		memset(p, 0, sizeof p);
		int a, b, q;
		cin >> a >> b >> q;
		int l = a * b / __gcd(a, b);
		vi ok;
		for(int i = 0; i < l; i++) {
			if(i % a % b != i % b % a) {
				p[i] = 1;
			}
		}
		for(int i = 1; i < l; i++) p[i] += p[i-1];
		while(q--) {
			int lb, rb;
			cin >> lb >> rb;
			cout << go(rb, l) - go(lb-1, l) << ' ';
		}
		cout << '\n';
	}	
	
}