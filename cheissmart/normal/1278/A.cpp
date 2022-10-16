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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		string p, h;
		cin >> p >> h;
		sort(ALL(p));
		bool ok = false;
		for(int i=0;i+p.size()-1<h.size();i++) {
			string r = h.substr(i, p.size());
			sort(ALL(r));
			if(r == p) ok = true;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}	
	
}