#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		string s, g;
		cin >> n >> k >> g;
		s += '1';
		for (int i = 0; i < k; i++){
			s += '0';
		}
		s += g;
		for (int i = 0; i < k; i++){
			s += '0';
		}
		s += '1';
		vector <int> v;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '1'){
				v.push_back (i);
			}
		}
		int ans = 0;
		for (int i = 0; i < v.size() - 1; i++)
			ans += (v[i + 1] - v[i] - k - 1) / (k + 1);
		cout << ans << '\n';
	}
}