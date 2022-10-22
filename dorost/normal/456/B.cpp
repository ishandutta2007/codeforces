#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string f;
	cin >> f;
	char c1, c2;
	c2 = f[f.size() - 1];
	if (f.size() == 1){
		c1 = '0';
	}else{
		c1 = f[f.size() - 2];
	}
	string s;
	s += c1;
	s += c2;
	int n = stoi(s);
	int ans = 1;
	if (n % 4 == 0){
		ans += 1;
	}else{
		ans += pow(2, n % 4);
	}
	if (n % 2){
		ans += 4;
	}else{
		ans += 6;
	}
	int v[] = {1,3,9, 7};
	ans += v[n % 4];
	cout << ans % 5;
}