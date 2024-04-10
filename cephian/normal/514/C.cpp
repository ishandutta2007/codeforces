#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll M1 = 1e9+7, M2 = 1e9+9;

set<pll> hashes;
int n,m;
string s;

ll pw(ll a, ll b, ll m) {
	if(!b) return 1;
	if(b&1) return a*pw(a,b-1,m)%m;
	ll t = pw(a,b/2,m);
	return t*t%m;
}

pll calc_hash(const string& s) {
	ll h1=0, h2=0;
	for(int i = s.size()-1; i >= 0; --i) {
		h1 *= 13;
		h2 *= 5;
		h1 += s[i] - 'a' + 1;
		h2 += s[i] - 'a' + 1;
		h1 %= M1;
		h2 %= M2;
	}
	return pll(h1,h2);
}

pll correct(pll h, char from, char to, int ind) {
	h.first += pw(13,ind,M1)*(to-from);
	h.second += pw(5,ind,M2)*(to-from);
	h.first = (h.first%M1+M1)%M1;
	h.second = (h.second%M2+M2)%M2;
	return h;
}

ostream& operator<<(ostream& o, const pll& p) {
	o << "(" << p.first << "," << p.second << ")";
	return o;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		hashes.insert(calc_hash(s));
	}
	for(int i = 0; i < m; ++i) {
		cin >> s;
		pll h = calc_hash(s);
		for(int j = 0; j < s.size(); ++j) {
			for(char c = 'a'; c <= 'c'; ++c) {
				if(c == s[j]) continue;
				if(hashes.count(correct(h,s[j],c,j))) {
					cout << "YES\n";
					goto skp;
				}
			}
		}
		cout << "NO\n";
		skp:;
	}



	return 0;
}