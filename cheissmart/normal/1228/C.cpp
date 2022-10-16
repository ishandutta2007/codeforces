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

const int M = 1e9 + 7;

int pw[100];

int mypw(int a, int b) {
	if(b == 0) return 1;
	int t = mypw(a, b/2);
	if(b&1) return t * t % M * a % M;
	else return t * t  % M;
}

int32_t main()
{
	IO_OP;
	
	int x, n;
	cin >> x >> n;
	vi ps;
	for(int i=2;i*i<=x;i++) {
		if(x % i) continue;
		while(x%i == 0) x /= i;
		ps.PB(i);
	}
	if(x != 1) ps.PB(x);
	int ans = 1;
	for(int p:ps) {
		pw[0] = 1;
		int i;
		for(i=1;;i++) {
			pw[i] = pw[i-1] * p;
			if(pw[i] > (n+p-1)/p) break;
		}
		int last = 0;
		for(int j=i;j>=1;j--) {
			int cur = n / pw[j];
			ans = ans * mypw(p, j*(cur - last)) % M;
			last = cur;
		}
	}
	cout << ans << endl;
}