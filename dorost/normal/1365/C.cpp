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
	int a[n], b[n];
	map <int, int> mp1, mp2;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mp1[a[i] - 1] = i;
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
		mp2[b[i] - 1] = i;
	}
	map <int, int> mp, mpo;
	for (int i = 0; i < n; i++){
		int a1 = min(mp1[i], mp2[i]);
		int a2 = max(mp1[i], mp2[i]);
		int ans1 = a2 - a1;
		int ans2 = n - ans1;
		if (mp1[i] > mp2[i]){
			mp[ans1]++;
			mpo[ans2] ++;
		}else{
			mp[ans2] ++;
			mpo[ans1]++;
		}
	}
	int mx = 0;
	for (auto x : mp){
		mx = max(mx, x.S);
	}
	for (auto x : mpo){
		mx = max(mx, x.S);
	}
	cout << mx << endl;
}