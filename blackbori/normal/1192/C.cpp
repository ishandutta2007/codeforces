#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 62;
const ll mod = 998244353;

ll D[66][66][66], K[66][66];
vector <string> S[11];
ll n, ans;

int getv(char c)
{
	if('a' <= c && c <= 'z') return c - 'a';
	else if('A' <= c && c <= 'Z') return c - 'A' + 26;
	else return c - '0' + 52;
}

ll calc()
{
	int i, j, k, l;
	ll ret = 0, v;
	
	for(i=0; i<sz; i++) for(j=i; j<sz; j++){
		for(k=j; k<sz; k++) for(D[i][j][k] = l = 0; l<sz; l++){
			D[i][j][k] = (D[i][j][k] + K[i][l] * K[j][l] % mod * K[k][l]) % mod;
		}
	}
	
	for(i=0; i<sz; i++) for(j=i; j<sz; j++){
		for(k=j; k<sz; k++) for(l=k; l<sz; l++){
			v = 24;
			if(i == l) v /= 24;
			else if(i == k) v /= 6;
			else if(i == j) v /= 2;
			if(i != j){
				if(j == l) v /= 6;
				else if(j == k) v /= 2;
			}
			if(j != k){
				if(k == l) v /= 2;
			}
			
			v = v * (D[i][j][k] * D[i][j][l] % mod) % mod;
			v = v * (D[i][k][l] * D[j][k][l] % mod) % mod;
			
			ret = (ret + v) % mod;
		}
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	int i, j, k;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> s;
		S[s.size()].push_back(s);
		reverse(s.begin(), s.end());
		S[s.size()].push_back(s);
	}
	
	for(i=3; i<=10; i++){
		sort(S[i].begin(), S[i].end());
		S[i].erase(unique(S[i].begin(), S[i].end()), S[i].end());
		
		for(j=0; j<sz; j++){
			for(k=0; k<sz; k++){
				K[j][k] = 0;
			}
		}
		
		for(string &t: S[i]){
			K[getv(t[0])][getv(t[i - 1])] ++;
		}
		
		ans = (ans + calc()) % mod;
	}
	
	cout << ans << "\n";
	
	return 0;
}