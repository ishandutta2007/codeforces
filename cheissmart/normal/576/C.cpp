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

	int n;
	cin >> n;
	V<array<int, 3>> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
		v[i][2] = i + 1;
	}
	int k = sqrt(n);
	sort(ALL(v), [&] (array<int, 3> a, array<int, 3> b) {
		return MP(a[0] / k, (((a[0] / k) & 1) ? 1 : -1) * a[1]) < MP(b[0] / k, (((b[0] / k) & 1) ? 1 : -1) * b[1]);
	});
	for(int i = 0; i < n; i++)
		cout << v[i][2] << ' ';
	
}