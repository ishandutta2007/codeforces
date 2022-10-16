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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, x= 0, y = 0;
		cin >> n;
		vi v;
		for(int i=0;i<n;i++) {
			string s;
			cin >> s;
			for(char c:s)
				if(c == '0') x++;
				else y++;
			v.PB(s.size());
		}
		sort(ALL(v));
		int ans = 0;
		int z = x / 2 + y / 2, zz = x % 2 + y % 2;
		for(int i=0;i<v.size();i++) {
			int m = v[i];
			if(m % 2 == 0) {
				int re = m / 2;
				if(z >= re) z -= re;
				else break;
			} else {
				int re = m / 2;
				if(z >= re) z -= re;
				else break;
				if(zz) zz--;
				else if(z) z--, zz++;
				else break;
			}
			ans++;
		}
		cout << ans << endl;
	}	
	
}