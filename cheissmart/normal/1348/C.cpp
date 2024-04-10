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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		sort(ALL(s));
		if(s[k-1] != s[0] || k == n) {
			cout << s[k-1] << endl;
			continue;
		}
		string ss = s.substr(k);
		string t = ss;
		t.resize(unique(ALL(t))-t.begin());
		if(t.size() == 1) {
			int tt = ((int)ss.size() + k - 1) / k;
			cout << s[k-1];
			for(int i=0;i<tt;i++) cout << t[0];
			cout << endl; 
		} else {
			cout << s[k-1] << ss << endl;
		}
	}	
	
}