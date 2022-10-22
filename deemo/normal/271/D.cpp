#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int BASE = 721;
const int BASE2 = 701;
const int MAX = 2e3 + 20;

string s, t;
int n, k;
ll p[MAX], s1[MAX], s2[MAX], h1[MAX], h2[MAX];
set<ll>	st;

ll get(int l, int r){
	ll temp = (h1[l] * s1[r - l]) % MOD;
	ll a = (h1[r] + MOD - temp) % MOD;

	temp = (h2[l] * s2[r - l]) % MOD;
	ll b = (h2[r] + MOD - temp) % MOD;
	
	ll ret = (a << ll(31)) ^ b;
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t >> k;	
	n = s.size();
	for (int i = 0; i < n; i++){
		p[i + 1] = p[i] + bool(t[s[i] - 'a'] == '0');
		h1[i + 1] = (h1[i] * BASE + s[i]) % MOD;
		h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD;
	}

	s1[0] = s2[0] = 1;
	for (int i = 1; i < MAX; i++)
		s1[i] = (s1[i - 1] * BASE) % MOD, s2[i] = (s2[i - 1] * BASE2) % MOD;

	for (int l = 0; l < n; l++)
		for (int r = l + 1; r <= n; r++){
			if (p[r] - p[l] > k)	break;
			st.insert(get(l, r));
		}
	cout << st.size() << endl;
	return 0;
}