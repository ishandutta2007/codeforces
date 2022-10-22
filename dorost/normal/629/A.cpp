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
	vector <pair <int, int>> v;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			char c;
			cin >> c;
			if (c == 'C')
				v.push_back({i, j});
		}
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++){
		for (int j = i + 1; j < v.size(); j++){
			if (v[i].F == v[j].F || v[i].S == v[j].S)
				ans ++;
		}
	}
	cout << ans;
}