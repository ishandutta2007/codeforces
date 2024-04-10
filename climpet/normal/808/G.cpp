#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	int tlen = t.size();
	vector<int> mp(tlen + 1, -1);
	int k = -1;
	for(int i = 0; i < tlen; ++i){
		while(k >= 0 && t[k] != t[i]){ k = mp[k]; }
		mp[i + 1] = ++k;
	}
	vector<int> dp1(tlen + 1, INT_MIN), dp2;
	dp1[0] = 0;
	for(char c : s){
		dp2.assign(tlen + 1, INT_MIN);
		dp2[0] = dp1[0];
		for(int i = 0; i < tlen; ++i){
			if(c == '?' || t[i] == c){
				dp2[i + 1] = dp1[i];
			}
		}
		++dp2[tlen];

		for(int i = tlen; i > 0; --i){
			int u = mp[i];
			dp2[u] = max(dp2[u], dp2[i]);
		}

		dp1.swap(dp2);
	}
	cout << *max_element(dp1.begin(), dp1.end()) << '\n';
}