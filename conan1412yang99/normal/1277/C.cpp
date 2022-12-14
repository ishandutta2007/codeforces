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

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vi rm;
		for(int i=0;i<(int)s.size()-2;i++) {
			string t;
			t.PB(s[i]), t.PB(s[i+1]), t.PB(s[i+2]);
			if(t == "one") {
				rm.PB(i+1);
				i++;
			}
			else if(t == "two") {
				if(i+3 < s.size() && s[i+3] == 'o') {
					rm.PB(i+1);
					i++;
				} else {
					rm.PB(i+2);
					i += 2;
				}
			}
		}
		cout << rm.size() << endl;
		for(int e:rm) cout << e+1 << " ";
		cout << endl;
	}	
	
}