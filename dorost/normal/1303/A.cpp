#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == '0'){
				ans++;
			}
		}
		for (int i = 0; i < n; i++){
			if (s[i] == '0'){
				ans--;
			}else{
				break;
			}	
		}
		for (int i = n - 1; i >= 0; i--){
			if (s[i] == '0'){
				ans--;
			}else{
				break;
			}
		}
		cout << max(0, ans) << endl;
	}
}