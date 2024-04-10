#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
#define int long long

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size(); 
		int x = -1, mx = -1;
		for (int i = 0; i < n; i++){
			if (s[i] == 'R'){
				mx = max(mx, i - x);
				//cout << "#" << i - x;
				x = i;
			}
		}
		if (mx == -1)
			cout << n + 1 << endl;
		else{
			mx = max(mx, n - x);
			cout << mx << endl;
		}
	}
}