#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	vi a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	auto ok = [&] (int m) {
		vi b(n + 1);
		int mnp = INF;
		for(int i = 1; i <= n; i++) {
			if(a[i] >= m) b[i] = 1;
			else b[i] = -1;
			b[i] += b[i - 1];
			if(i >= k) {
				mnp = min(mnp, b[i - k]);
			}
			if(b[i] - mnp > 0) return true;
		}
		return false;
	};

	int lb = 0, rb = n;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		if(ok(mb)) lb = mb + 1;
		else rb = mb - 1;
	}
	cout << rb << '\n';

}