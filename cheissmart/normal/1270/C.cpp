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

void solve() {
	int s = 0, x = 0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		s += t;
		x ^= t;
	}
	for(int j=0;j<2;j++){
		int lena = __lg(s) + 2;
		int a = 1LL << lena;
		if(s & 1)
			a++;
		if(j == 1) a |= 2;	
		int as = a + s, b = 0;
		for(int i=1;i<63;i++) {
			b |= (((as >> i & 1) ^ (x >> (i-1) & 1))) << (i-1);
		}
		if(a%2 != b%2) continue;
		cout << 3 << endl;
		cout << b << " " << (a-b)/2 << " " << (a-b)/2 << endl;
		assert(s+b+(a-b)/2+(a-b)/2 == 2 * (b ^ x));
		return;
	}
}

signed main()
{
	IO_OP;
	int T;
	cin >> T;
	while(T--) solve();
	
	
}