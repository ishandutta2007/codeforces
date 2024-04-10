#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int>& a){
	int n = (int)a.size();
	map<int, vector<int>> mp;
	for(int i = 0; i < n; ++i){
		mp[a[i]].push_back(i);
	}
	
	int sz = 0;
	for(auto vec: mp){
		int odd = 0, even = 0;
		for(auto i: vec.second){
			if ((i - sz) & 1) odd++;
			else even++;
		}
		
		if (odd != even && odd != even - 1){
			return false;
		}
		
		sz += (int)vec.second.size();
	}
	
	return true;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		
		cout << (ok(a) ? "YES" : "NO") << endl;
	}
	return 0;
}