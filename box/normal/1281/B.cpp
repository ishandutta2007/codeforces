#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ll=long long;
using pii=pair<int, int>;
#define int ll
const int MOD = 1000000007;
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

vector<pair<char, int>> vp;
string s;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> s;
		vp.clear();
		rep(i, s.length()) {
			vp.push_back({s[i], i});
		}
		sort(all(vp));
		rep(i, s.length()) {
			if(vp[i].first == s[i]) continue;
			else {
				char c = vp[i].first;
				int ans = vp[i].second;
				rep(j, s.length()) {
					if(s[j] == c) ans = j;
				}
				swap(s[i], s[ans]);
				break;
			}
		}
		string c; cin >> c;
		if(s < c) cout << s << endl;
		else cout << "---" << endl;
	}
}