#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int>& a){
	int n = (int)a.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			for(int k = 0; k < j; ++k){
				if (a[i] >= a[j] && a[j] >= a[k]) return false;
				if (a[i] <= a[j] && a[j] <= a[k]) return false;
			}
		}
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
		
		long long res = 0;
		for(int i = 0; i < n; ++i){
			vector<int> b;
			for(int j = i; j < i + 6 && j < n; ++j){
				b.push_back(a[j]);
				res += ok(b);
			}
		}
				
		cout << res << endl;
	}
	return 0;
}