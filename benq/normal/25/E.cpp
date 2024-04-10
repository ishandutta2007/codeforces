#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int MOD = 1000000009;
int ans = MOD;

ll po[100001];

ll hsh(string x) {
	ll cur = 0;
	F0R(i,x.length()) cur = (cur+po[i]*(x[i]-'a'+1)) % MOD;
	return cur;
}

bool isub(string a, string b) {
	ll rec = hsh(a), cur = hsh(b.substr(b.length()-a.length(),a.length()));
	if (cur == rec) return 1;
	for (int i = b.length()-a.length()-1; i >= 0; --i) {
		cur = (cur-po[a.length()-1]*(b[i+a.length()]-'a'+1)) % MOD;
		cur = ((cur*po[1]+(b[i]-'a'+1)) % MOD + MOD) % MOD;
		if (cur == rec) return 1;
	}
	return 0;
}

bool comp(string a, string b) {
	return (a.length()>b.length());
}

int get(string a, string b) {
	int cur = b.length();
	
	ll c1 = 0, c2 = 0;
	for (int i = a.length()-1; i >= max(0,(int)(a.length()-b.length())); --i) {
		c1 = (po[1]*c1+(a[i]-'a'+1)) % MOD;
		c2 = (c2+po[a.length()-1-i]*(b[a.length()-1-i]-'a'+1)) % MOD;
		if (c1 == c2) cur = i+b.length()-a.length();
	}
	return cur;
}

int main() {
	po[0] = 1;
	FOR(i,1,100001) po[i] = (12341*po[i-1]) % MOD;
	
	vector<string> s(3); F0R(i,3) cin >> s[i];
	sort(s.begin(),s.end(),comp);
	
	if (isub(s[2],s[0]) || isub(s[2],s[1])) s.erase(s.begin()+2);
	if (isub(s[1],s[0])) s.erase(s.begin()+1);
	sort(s.begin(),s.end());
	
	do {
		int cur = s[0].length();
		F0R(i,s.size()-1) cur += get(s[i],s[i+1]);
		ans = min(ans,cur);
	} while (next_permutation(s.begin(),s.end()));
	cout << ans;
}