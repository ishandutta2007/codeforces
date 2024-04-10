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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int pos[N];

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	int l = 0, r = -1;
	while(q--) {
		char op;
		int id;
		cin >> op >> id;
		if(op == 'L') {
			pos[id] = --l;
		} else if(op == 'R') {
			pos[id] = ++r;
		} else {
			cout << min(pos[id]-l, r-pos[id]) << endl;
		}
	}
	
}