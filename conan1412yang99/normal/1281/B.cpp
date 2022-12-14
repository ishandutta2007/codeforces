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

void solve() {
	string s, t;
	cin >> s >> t;
	if(s < t) {
		cout << s << endl;
		return;
	}
	for(int i=0;i<s.size();i++) {
		char mn = s[i];
		for(int j=i+1;j<s.size();j++) mn = min(mn, s[j]);
		if(s[i] != mn) {
			for(int j=i+1;j<s.size();j++){
				swap(s[i], s[j]);
				if(s < t) {
					cout << s << endl;
					return;
				} 
				swap(s[i], s[j]);
			} 
			break;
		}
	}
	cout << "---" << endl;
}

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		solve();
	}	
	
}