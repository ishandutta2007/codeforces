#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

string s,p;
int n,m,first[1001],last[1001];
ll base = 2341, inv = 505339602, po2[1001];

void genfirst() {
	FOR(i,1,p.length()+1) first[i] = MOD;
	
	ll des = p[0]-'A'+1;
	ll cur = s[0]-'A'+1;
	ll clen = 1;
	int i = 0;
	while (1) {
		if (des == cur) {
			first[clen] = i+clen-1;
			if (i+clen >= n) break;
			des = (des + po2[clen] * (p[clen]-'A'+1)) % MOD;
			cur = (cur + po2[clen] * (s[i+clen]-'A'+1)) % MOD;
			clen ++;
		} else {
			if (i+clen >= n) break;
			cur = (cur-(s[i]-'A'+1)) % MOD;
			while (cur<0) cur += MOD;
			cur = (cur*inv) % MOD;
			cur = (cur+(s[i+clen]-'A'+1)*po2[clen-1]) % MOD;
			i++;
		}
	}
}

void gensecond() {
	FOR(i,1,p.length()+1) last[i] = -1;
	
	ll des = p[p.length()-1]-'A'+1;
	ll cur = s[n-1]-'A'+1;
	ll clen = 1;
	
	int i = n-1;
	while (1) {
		if (des == cur) {
			last[clen] = i-clen+1;
			if (i-clen < 0) break;
			des = (base * des + (p[p.length()-1-clen]-'A'+1)) % MOD;
			cur = (base * cur + (s[i-clen]-'A'+1)) % MOD;
			clen ++;
		} else {
			if (i-clen < 0) break;
			cur = (cur-po2[clen-1]*(s[i]-'A'+1)) % MOD;
			while (cur<0) cur += MOD;
			cur = (cur*base) % MOD;
			cur = ((s[i-clen]-'A'+1)+cur) % MOD;
			i--;
		}
	}
}

bool test() {
	genfirst();
	gensecond();
	FOR(i,1,p.length()) if (first[i]<last[p.length()-i]) return 1;
	return 0;
}

int main() {
	cin >> s >> m;
	n = s.length();
	int ans = 0;
	po2[0] = 1;
	FOR(i,1,1001) po2[i] = (base*po2[i-1]) % MOD;
	F0R(i,m) {
		cin >> p;
		if (test()) ans++;
	}
	cout << ans;
}