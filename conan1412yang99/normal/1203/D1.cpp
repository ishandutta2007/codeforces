#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

bool ok(string &s, string &t) {
	int j = 0;
	for(int i=0;i<s.size();i++) {
		if(s[i] == t[j]) j++;
	}
	return j == t.size();
}

int32_t main() {
	
	string s, t;
	cin >> s >> t;
	int ans = 0;
	for(int i=0;i<s.size();i++) {
		for(int j=i;j<s.size();j++) {
			int len = j - i + 1;
			string r = s.substr(0, i);
			if(j < s.size()-1) r += s.substr(j+1);
			if(ok(r, t))
				ans = max(len, ans);
		}
	}
	cout << ans << endl;
	return 0;
}