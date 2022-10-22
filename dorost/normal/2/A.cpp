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
	map <string, int> mp, mp2;
	int mx = -1000;
	vector <pair <string, int>> v;
	string s[n];
	for (int i = 0; i < n; i++){
		int m;
		cin >> s[i] >> m;
		mp[s[i]] += m;
		v.push_back({s[i], m});
	}
	for (int i = 0; i < v.size(); i++){
		mx = max(mx, mp[v[i].F]);
	}
//	cout << mx << endl;
	string ans = "1";
	int an = n + 10;
	for (int i = 0; i < v.size(); i++){
		if (mp[v[i].F] == mx){
			int sum = 0;
			int an2 = i;
			for (int j = 0; j < n; j++){
				if (v[j].F == v[i].F){
					sum += v[j].S;
				}
				if (sum >= mx){
					an2 = j;
					break;
				}
			}
			if (an2 < an){
				an = an2;
				ans = v[i].F;
			}
		}
	}
//	cout << mp["jpdwmyke"] << ' ' << mp["aawtvezfntstrcpgbzjbf"] << endl;
	cout << ans;
}