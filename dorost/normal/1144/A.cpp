#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size();
		sort(s.begin(), s.end());
		char c = s[0];
		bool f = true;
		for (int i = 1; i < n; i++){
			if (s[i] != c + 1){
				f = false;
				break;
			}
			c++;
		}
		cout << (f ? "YES\n" : "NO\n");
	}	
}