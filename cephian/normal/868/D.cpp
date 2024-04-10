#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int B = 15;
vector<string> st={""},ed={""};
vector<map<int,set<string>>> sub;

int main() {	
	fio;
	int n,m;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		st.pb(s), ed.pb(s);
		sub.resize(st.size());
		sub[i][0].insert("");
		for(int j = 0; j < s.size(); ++j) {
			for(int l = 1; j+l <= s.size() && j <= B; ++l) {
				sub[i][l].insert(s.substr(j,l));
			}
		}
	}
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		int a,b;
		cin >> a >> b;
		string _st = st[a] + st[b];
		string _ed = ed[a] + ed[b];
		if(_st.size() > B)
			_st = _st.substr(0,B);
		if(_ed.size() > B)
			_ed = _ed.substr(_ed.size()-B,B);
		st.pb(_st), ed.pb(_ed);
		string mid = ed[a] + st[b];
		sub.resize(st.size());
		int I = n+i;
		for(int j = 0; j < mid.size(); ++j) {
			for(int l = 1; j+l <= mid.size() && l <= B; ++l) {
				sub[I][l].insert(mid.substr(j,l));
			}
		}

		for(auto A : sub[a]) {
			sub[I][A.fi].insert(A.se.begin(),A.se.end());
		}

		for(auto A : sub[b]) {
			sub[I][A.fi].insert(A.se.begin(),A.se.end());
		}

		int ans = 0;
		while(sub[I][ans+1].size() == (1<<(ans+1))) {
			++ans;
		}
		cout << ans << endl;
	}

}