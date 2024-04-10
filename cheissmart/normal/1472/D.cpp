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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(ALL(a));
		int who = 0;
		ll score[2] = {};
		while(a.size()) {
			if(a.back() % 2 == who) score[who] += a.back();
			a.pop_back();
			who ^= 1;
		}
		if(score[0] > score[1]) cout << "Alice" << endl;
		else if(score[0] < score[1]) cout << "Bob" << endl;
		else cout << "Tie" << endl;
 	}


	
}