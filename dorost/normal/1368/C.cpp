/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <pair <int, int>> v;
	for (int i = 0; i <= n; i++){
		v.push_back({i, i});
		v.push_back({i, i + 1});
		v.push_back({i + 1, i});
	}
	v.push_back({n + 1, n + 1});
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i ++){
		cout << v[i].F << ' ' << v[i].S << endl;
	}
}