#include<bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())

const int N = int(1e6) + 9;
const int MOD = 998244353;

int n;
string s, l, r;
int dp[N];
int sumDP[N];

int sum(int a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

vector <int> z_function(string s){
	int n = sz(s);
	vector <int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}

//s[pos..] ? t
char cmp(vector <int> &zf, string &t, int pos){
	int len = sz(t);
	assert(pos + len + 1 < sz(zf));
	if(sz(s) - pos < len) return '<';
	
	int x = zf[len + 1 + pos];
	assert(x <= len);
	if(x == len) return '=';
	assert(pos + x < sz(s));
	assert(s[pos + x] != t[x]);
	if(s[pos + x] < t[x]) return '<';
	return '>';
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> s >> l >> r;
	n = int(s.size());
	vector <int> zl = z_function(l + "#" + s);
	vector <int> zr = z_function(r + "#" + s);
	
	sumDP[n] = dp[n] = 1;
	for(int i = n - 1; i >= 0; --i){
		if(s[i] == '0'){
			if(l == "0") dp[i] = dp[i + 1];		
			else dp[i] = 0;
			sumDP[i] = sum(dp[i], sumDP[i + 1]);
			continue;
		}
		
		int L = sz(l) + i;
		char cl = cmp(zl, l, i);
		if(cl == '<') ++L;
		
		int R = sz(r) + i;
		char cr = cmp(zr, r, i);
		if(cr == '>') --R;

	 	int cur = 0;
	 	if(L <= R && L <= n){
	 		R = min(R, n);
	 		cur = sumDP[L];
	 		if(R != n) cur = sum(cur, MOD - sumDP[R + 1]);
	 	}
	 	dp[i] = cur;
	 	sumDP[i] = sum(dp[i], sumDP[i + 1]);
	}
	
	cout << dp[0] << endl;
	return 0;
}