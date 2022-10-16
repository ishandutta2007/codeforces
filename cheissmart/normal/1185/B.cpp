#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vector<pair<char, int>> f(string s) {
	vector<pair<char, int>> v;
	v.EB(s[0], 1);
	for(int i=1;i<s.size();i++) {
		if(s[i] == v.back().F)
			v.back().S++;
		else
			v.EB(s[i], 1);
	}
	return v;
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	while(n--) {
		string s, t;
		cin >> s >> t;
		vector<pair<char, int>> v1 = f(s), v2 = f(t);
		if(v1.size() != v2.size()) {
			cout << "NO" << endl;
			continue;
		}
		bool yes = 1;
		for(int i=0;i<v1.size();i++) {
			if(v1[i].F != v2[i].F) yes = 0;
			if(v1[i].S > v2[i].S) yes = 0;
		}
		if(yes) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}