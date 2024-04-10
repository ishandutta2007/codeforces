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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int x; cin >> x;
		string s; cin >> s;
		ll len = s.length();
		rep(i, x) {
			len = (len + (s[i]-'1')*(len-i-1+MOD)) % MOD;
			int le = s.length();
			rep(j, s[i]-'1') {
				if(s.length() >= x) break;
				iter(k, i+1, le) {
					s += s[k];
					if(s.length() >= x) break;
				}
			}
		}
		cout << len << endl;
	}
}