#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(max(l1, l2) <= min(r1, r2))
			cout << max(l1, l2) << '\n';
		else
			cout << l1 + l2 << '\n';
	}

}