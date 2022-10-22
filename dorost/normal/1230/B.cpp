#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	// int a,b,c,d;
	// cin >> a >> b >> c >> d;
	// if((a) == (b + c + d)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// if((b) == (a + c + d)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// if((c) == (b + a + d)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// if((d) == (b + c + a)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// if((a + b) == (c + d)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// if((a + c) == (b + d)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// if((a + d) == (b + c)){
	// 	cout << "YES";
	// 	return 0;
	// }
	// cout << "NO";
	string s;
	ll k ,n;
	cin >> n >> k >> s;
	for(ll i = 0; i < n; i++){
		if(k == 0){
			break;
		}
		if((s[i] > '0') && (n == 1)){
			cout << '0';
			return 0;
		}else if((i == 0) && (s[0] > '1') && k){
			s[0] = '1';
			k--;
		}else if(k && (s[i] > '0') && (i != 0)){
			k--;
			s[i] = '0';
		}
	}
	cout << s;
}