#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define mp make_pair
#define pb push_back

const int MOD = 1000000007;

string t,s1,s2;
ll po[2000], inv = 505339602;
set<ll> hashes[2001];
bool posi[2][2000];

vi gen(string s, int x) {
	vi a;
	if (s.length() > t.length()) return a;
	ll h1=0, h2=0;
	F0R(i,s.length()) {
		h1 = (h1+po[i]*(s[i]-'a'+1)) % MOD;
		h2 = (h2+po[i]*(t[i]-'a'+1)) % MOD;
	}
	for (int i = 0;; ++i) {
		if (h1 == h2) posi[x][i] = 1;
		if (i == t.length()-s.length()) break;
		else {
			h2 = (h2-(t[i]-'a'+1)) % MOD;
			h2 = (inv*h2) % MOD;
			h2 = (h2+po[s.length()-1]*(t[i+s.length()]-'a'+1)) % MOD;
		}
	}
}

int main() {
	cin >> t >> s1 >> s2;
	po[0] = 1;
	F0R(i,1999) po[i+1] = (2341*po[i]) % MOD;
	gen(s1,0), gen(s2,1);
	F0R(i,t.length()) if (posi[0][i]) {
		ll chash = 0;
		FOR(j,i,t.length()) {
			chash = (chash+po[j-i]*(t[j]-'a'+1)) % MOD;
			if (j-(int)s2.length()+1 >= i && i+(int)s1.length()-1 <= j) 
				if(posi[1][j-s2.length()+1] == 1) 
					hashes[j-i+1].insert(chash);
		}
	}
	ll ans = 0;
	FOR(i,1,2001) ans += hashes[i].size();
	cout << ans;
}