/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	string s = "";
	int a[n], cnt = 0, cnt2 = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 0)
			s += '0', cnt2 ++;
		else
			cnt++;
	}
	cnt = cnt / 9 * 9;
	if (cnt2 == 0)
		cnt = 0;
	for (int i = 0; i < cnt; i++){
		s += '5';
	}
	if (cnt <= 0){
		if (cnt2 == 0){
			cout << -1;
		}else{
			cout << '0';
		}
	}else{
		reverse (s.begin(), s.end());
		cout << s;
	}
}