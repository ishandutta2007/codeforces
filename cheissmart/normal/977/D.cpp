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

signed main()
{
	IO_OP;

	V<array<int, 3>> v;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int tt = t;
		int a = 0, b = 0;
		while(t % 2 == 0) a++, t /= 2;
		while(t % 3 == 0) b++, t /= 3;
		v.PB({a, -b, tt});
	}
	sort(ALL(v));
	for(int i = 0; i < n; i++) cout << v[i][2] << " ";
	cout << endl;
	
}