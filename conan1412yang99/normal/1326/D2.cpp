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

const int INF = 1e9 + 7, N = 1e6 + 7;

int f[N * 2 + 1];

string go(string s) {
	if(s.empty()) return s;
	string t;
	t += s + "#";
	reverse(ALL(s));
	t += s;
	int j = f[0] = -1;
	for(int i=1;i<t.size();i++) {
		while(j != -1 && t[j+1] != t[i]) j = f[j];
		if(t[j+1] == t[i]) j++;
		f[i] = j;
	}
	return t.substr(0, j + 1);
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int l = 0, r = s.size() - 1;
		while(l < r) {
			if(s[l] == s[r]) l++, r--;
			else break;
		}
		string t = s.substr(l, r - l + 1);
		string ans1 = go(t);
		reverse(ALL(t));
		string ans2 = go(t);
		if(ans1.size() < ans2.size()) swap(ans1, ans2);
		cout << s.substr(0,l) + ans1 + (r + 1 < s.size() ? s.substr(r + 1) : "") << endl;
	}	
	
}