#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long res = a.back();
		long long sum = 0;
		for(int i = 0; i < n; ++i){
			res -= i * (long long) a[i] - sum;
			sum += a[i];
		}
		
		cout << res << endl;
	}
	return 0;
}