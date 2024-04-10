#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, k, ans = -1;
	cin >> n >> k;
	string s, t, r;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		t += s[i];
		r += s[n - i - 1];
		string g = r;
		reverse(g.begin(), g.end());
		if (t == g){
			bool f = false;
			for (int i = 0; i < s.size() - 1; i++){
				if (s[i] != s[i + 1])
					f = true;
			}
			if (i != n - 1) 
				ans = i;
		}
//		cout << t << ' ' << g << endl;
	}
//  	cout << ans << endl;
	for (int i = 0; i < k; i++){
		if (i == 0){
			cout << s;
		}else{
			for (int j = ans + 1; j < s.size(); j++){
				cout << s[j];
			}
		}
	}
}