/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 110;
bool f[N];

int32_t main(){
	int n;
	string s;
	cin >> n >> s;
	f[0] = true;
	set <char> vow = {'a', 'e', 'i', 'o', 'u', 'y'};
	for (int i = 1; i < n; i++){
		if (!vow.count (s[i - 1]) || !vow.count(s[i]))
			f[i] = true;
	}
	for (int i = 0; i < n; i++)
		if (f[i])
			cout << s[i];
}