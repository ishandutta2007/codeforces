#include <iostream>
#include <map>

using namespace std;

int n,q;

string a[36],b[36];

map<string, bool> dp;
bool red(string s) {
	if(s.size() == 1) return s == "a";
	if(dp.count(s)) return dp[s];
	for(int i = 1; i < 2; ++i) {
		for(int j = 0; j < q; ++j) {
			if(s[i-1] == a[j][0] && s[i] == a[j][1]) {
				string tmp = s.substr(0, i-1) + b[j] + s.substr(i+1,s.size()-i-1);
				if(red(tmp)) {
					return dp[s] = 1;
				}
			}
		}
	}
	return dp[s] = 0;
}

int pw(int a, int b) {
	if(b == 0) return 1;
	return a*pw(a,b-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 0; i < q; ++i)
		cin >> a[i] >> b[i];
	int ans =  0;
	for(int i = pw(6,n)-1; i >=0; --i) {
		int m = i;
		string s = "";
		for(int j = 0; j < n; ++j) {
			s += 'a' + m%6;
			m /= 6;
		}
		ans += red(s);
	}
	cout << ans << "\n";
	return 0;
}