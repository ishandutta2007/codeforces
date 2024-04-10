#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string s, ans;
		cin >> s;
		int f = 0;
		for (int  i = 0; i < n; i++){
			if ((s[i] - '0') % 2){
				//cout << s[i];
				f++;
				ans += s[i];
			}
		}
		if (f >= 2){
			cout << ans[0] << ans[1] << endl;
		}else{
			cout << -1 << endl;
		}
	}
}