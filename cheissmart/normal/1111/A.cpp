#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int m[256];

int main()
{
	IO_OP;
	m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
	string s, t;
	cin >> s >> t;
	if(s.size() != t.size()) {
		cout << "No" << endl;
		return 0;
	}
	for(int i=0;i<s.size();i++) {
		if(m[s[i]] != m[t[i]]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
}