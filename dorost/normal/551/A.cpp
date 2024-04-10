/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N], ans [N];
vector <int> mp[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], mp[a[i]].push_back(i + 1);
	int pos = 1;
	for (int i = N - 1; i >= 0; i --){
		for (int j = 0; j < mp[i].size(); j++){
			ans [mp[i][j]] = pos;
		}
		pos += mp[i].size();
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}