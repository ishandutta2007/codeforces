#include <bits/stdc++.h>
#define ll long long
 
using namespace std;


int main()
{
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, int> > v;
	for (int i=0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}	
	int ans = 0;
	for (int i=0; i < 100000; ++i){
		for (int j=0; j < n; ++j){
			if (i-v[j].second >= 0 && (i-v[j].second)%v[j].first == 0){
				if (s[j] == '0') s[j] = '1';
				else s[j] = '0';
			}
		}
		int tut = 0;
		for (int j=0;j<n;j++) tut += (s[j] - '0');
		ans = max(ans, tut);
	}
	cout << ans;

}