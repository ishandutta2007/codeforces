#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string n;
	cin >> n;
	reverse(n.begin(), n.end());
	map<string, int> dp;
	auto sub = [&](string x, string y){
		for(int i = 0; i < (int)y.size(); ++i){
			x[i] -= y[i] - '0';
			if(x[i] < '0'){
				x[i] += 10;
				x[i + 1] -= 1;
			}
		}
		while((int)x.size() && x[(int)x.size() - 1] == '0'){
			x.pop_back();
		}
		return x;
	};
	auto sol = [&](auto&&self, string s){
		if(dp[s]){
			return dp[s];
		}
		int x = (int)s.size();
		if(!x){
			return 0;
		}
		dp[s] = (int)1e9;
		int mi = s[x - 1] - '0';
		for(int i = x - 2; i >= 0; --i){
			if(s[i] > s[x - 1]){
				break;
			}
			if(s[i] < s[x - 1]){
				--mi;
				break;
			}
		}
		string b;
		if(mi >= 1){
			for(int i = 0; i < x; ++i){
				b += mi + '0';
			}
			b = sub(s, b);
			dp[s] = self(self, b) + mi * x;
		}
		else{
			for(int i = 0; i < x; ++i){
				b += '1';
			}
			b = sub(b, s);
			dp[s] = self(self, b) + x;
		}
		b.clear();
		for(int i = 0; i < x + 1; ++i){
			b += '1';
		}
		b = sub(b, s);
		if((int)b.size() <= x){
			dp[s] = min(dp[s], self(self, b) + x + 1);
		}
		return dp[s];
	};
	cout << sol(sol, n);
	return 0;
}