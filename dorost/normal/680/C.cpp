/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime (int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int32_t main(){
	int k = 20;
	int ans = 1;
	for (int i = 2; i <= 100; i++){
		if (!is_prime (i))
			continue;
		if (k > 0){
			cout << i << endl;
			k--;
		}
		string s;
		int x = i;
		while (k > 0){
			string s;
			cin >> s;
			if (s == "no")
				break;
			ans *= i;
			x *= i;
			if (x > 100)
				break;
			cout << x << endl;
			k--;
		}
	}
	cout << (is_prime(ans) ? "prime" : "composite");
}