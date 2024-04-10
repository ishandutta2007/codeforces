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
	
	string s;
	cin >> s;
	vi v({-1});
	for(int i = 0; i < s.size(); i++) if(s[i] == ',' || s[i] == ';')
		v.PB(i);
	v.PB(s.size());
	V<string> a, b;
	for(int i=0;i<v.size() - 1;i++) {
		string t = s.substr(v[i]+1, v[i+1]-v[i]-1);
		if(t == "0") {
			a.PB(t);
			continue;
		}
		bool ok = t.size() && t[0] != '0';
		for(char c:t) ok &= isdigit(c);
		if(ok) a.PB(t);
		else b.PB(t);
	}
	for(int i=0;i<2;i++) {
		if(a.empty()) cout << "-" << endl;
		else {
			cout << "\"";
			for(int j=0;j<a.size();j++) {
				if(j) cout << ",";
				cout << a[j];
			}
			cout << "\"" << endl;
		}
		swap(a, b);
	}
	
}