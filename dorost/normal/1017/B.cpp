/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int n01 = 0, n00 = 0, n10 = 0, n11 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == '1' && b[i] == '1')
			n11++;
		else if (a[i] == '1' && b[i] == '0')
			n10++;
		else if (a[i] == '0' && b[i] == '1')
			n01++;
		else
			n00++;
	}
	cout << n11 * n00 + n10 * n01 + n00 * n10;
}