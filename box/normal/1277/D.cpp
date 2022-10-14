// writer: piggydan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ordered_set=tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

set<string> rev;
set<string> no;
vector<string> inp;

inline int aabs(int x) {
	if(x < 0) return -x;
	return x;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		rev.clear(); no.clear(); inp.clear();
		int n; cin >> n;
		int zz = 0, zo = 0, oz = 0, oo = 0;
		vector<int> _ozo, _ooz; int ozop = 0, oozp = 0;
		rep(i, n) {
			string s; cin >> s;
			inp.push_back(s);
			if(s[0] == s.back()) {
				if(s[0] == '0') zz++;
				else oo++;
			} else {
				if(s[0] == '0') zo++;
				else oz++;

				string copy(s);
				reverse(all(copy));
				if(rev.find(copy) != rev.end()) {
					no.insert(s);
					no.insert(copy);
				} else {
					if(s[0] == '0') _ozo.push_back(i+1);
					else _ooz.push_back(i+1);
					rev.insert(s);
				}
			}
		}
		vector<int> ooz, ozo;
		for(int i:_ooz) {
			if(no.find(inp[i-1]) == no.end()) ooz.push_back(i);
		}
		for(int i:_ozo) {
			if(no.find(inp[i-1]) == no.end()) ozo.push_back(i);
		}

		vector<int> ans;

		if((zz && oo) && !(zo + oz)) goto cont;


		while(aabs(zo-oz) > 1) {
			if(zo > oz) {
				if(ozop == ozo.size()) goto cont;
				else {
					ans.push_back(ozo[ozop++]);
					zo--; oz++;
				}
			} else {
				if(oozp == ooz.size()) goto cont;
				else {
					ans.push_back(ooz[oozp++]);
					zo++; oz--;
				}
			}
		}

		cout << ans.size() << endl;
		for(int i:ans) cout << i << ' ';
		cout << endl;
		continue;

		cont:
		cout << -1 << endl;
	}
}