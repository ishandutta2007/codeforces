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
		int n;
		cin >> n >>  s;
		int k = 1;
		string mn = s;
		for(int i=2;i<=n;i++) {
			string t = s.substr(0, i - 1);			
			string tt = s.substr(i - 1);
			if((n-i+1)&1) reverse(ALL(t));
			tt += t;
			if(tt < mn) {
				mn = tt;
				k = i;
			}
		}
		cout << mn << endl;
		cout << k << endl;
	}
	
}