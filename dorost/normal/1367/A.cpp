#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size();
		string t = "";
		for (int i = 0; i < n; i++){
			if (i % 2 == 0 && i != 0)
				continue;
			t += s[i];
		}
		cout << t << endl;
	}
}