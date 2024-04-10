#include <bits/stdc++.h>
using namespace std;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector<int> ans;
		for(int a : {1,2,3,4,6,12}) {
			int b = 12/a;
			for(int i = 0; i < b; ++i) {
				bool ok = true;
				for(int j = 0; j < 12; j += b)
					ok &= s[j+i] == 'X';
				if(ok) {
					ans.push_back(a);
					break;
				}
			}
		}
		cout << ans.size();
		for(int a : ans) {
			cout << ' ' << a << 'x' << 12/a;
		}
		cout << '\n';
	}
}