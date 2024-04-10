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
	int a = (n * (n + 1)) / 2;
	int x = a / 2;
	cout << (a - (x)) - x << endl;
	int lst = n;
	vector <int> v;
	while (x){
		if (lst <= x)
			x -= lst, v.push_back(lst), lst--;
		else
			v.push_back(x), x = 0;
	}
	cout << v.size();
	int ans = 0;
	for (int i = 0; i < v.size(); i++){
		cout << ' ' << v[i];
		ans += v[i];
	}
	cerr << endl << ans << endl;
	cerr << a - ans << endl;
}