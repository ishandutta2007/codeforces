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
		int n;
		string s;
		cin >> n >> s;
		string a, b;
		bool yes = false;
		for(int i=0;i<n;i++) {
			if(s[i] == '0')
				a += '0', b += '0';
			else if(s[i] == '1') {
				if(yes) {
					a += '1';
					b += '0';
				} else {
					a += '0';
					b += '1';
					yes = true;
				}
			} else {
				if(yes) {
					a += '2';
					b += '0';
				} else {
					a += '1';
					b += '1';
				}
			}
		}
		cout << a << '\n';
		cout << b << '\n';
	}	
	
}