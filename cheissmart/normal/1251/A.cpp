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
		vi ok(26);
		string s;
		cin >> s;
		int r = 1;
		for(int i=1;i<s.size();i++) {
			if(s[i] == s[i-1]) {
				r++;
			} else {
				if(r & 1) ok[s[i-1]-'a'] = 1;
				r = 1;
			}
		}
		if(r & 1) ok[s[s.size()-1]-'a'] = 1;
		for(int i=0;i<26;i++)
			if(ok[i])
				cout << char(i + 'a');
		cout << endl;

	}	
	
}