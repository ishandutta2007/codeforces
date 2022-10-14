#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
//#define int ll
#define mo 9007199254740991ull

ll val[600005];
set<ll> ht;
string s;

ll hush() {
	ll ans = 0; int pos = 0;
	while(pos != s.length()) {
		ans = (ans + (s[pos] - 'a' + 1)*val[pos]) % mo;
		pos++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	val[0] = 1;
    iter(i, 1, 600001) val[i] = (val[i-1] * 3) % mo;
    int n, m; cin >> n >> m;
	rep(i, n) {
		cin >> s;
		ht.insert(hush());
	}
	rep(i, m) {
		cin >> s;
		ll h = hush();
		rep(pos, s.length()) {
			rep(j, 3) {
				if(j == s[pos] - 'a') continue;
				if(ht.find((5*mo+h+(j - s[pos] + 'a')*val[pos])%mo) != ht.end()) {
					cout << "YES" << endl;
					h = 0;
					break;
				}
			}
			if(!h) break;
		}
		if(h) cout << "NO" << endl;
	}
}