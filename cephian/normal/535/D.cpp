#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 1e9+7;
int n,m;
string s,p;
const int N = 1e6+5;
int y[N];
vi same;

//query polynomial hash of substring [l,r] of s
struct str_hash {
	vector<ll> h,b;
	const static ll BASE=37, MOD=1e9+9;
	str_hash(){}
	str_hash(const string& s):h(s.size()+1),b(s.size()+1,1) {
		for(int i = 0; i < s.size(); ++i) {
			h[i+1] = (h[i]*BASE + s[i]-'a'+1)%MOD;
			b[i+1] = (b[i]*BASE)%MOD;
		}
	}

	//inclusive range hash
	ll range_hash(int i, int j) {
		ll r = (h[j+1] - h[i]*b[j-i+1])%MOD;
		return (r<0)?r+MOD:r;
	}
};

str_hash ph;

bool ok(int i) {
	return ph.range_hash(i,p.size()-1) == ph.range_hash(0,p.size()-1-i);
}

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return a*pw(a,b-1)%M;
	ll t = pw(a,b/2);
	return t*t%M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> p;

	ph = str_hash(p);

	for(int i = 0; i < m; ++i) {
		cin >> y[i];
		--y[i];
		if(i) {
			int df = y[i]-y[i-1];
			if(df < p.size()) {
				if(!ok(df)) {
					cout << "0\n";
					return 0;
				}
			}
		}
	}
	s = string(n,'?');
	int j = 0;
	int ctr = p.size();
	int free = 0;
	for(int i = 0; i < n; ++i) {
		if(j < m && y[j] == i) {
			ctr = 0;
			++j;
		}
		if(ctr < p.size())
			s[i] = p[ctr];
		else ++free;
		++ctr;
	}
	// cout << s << "\n";
	cout << pw(26,free) << "\n";
	return 0;
}