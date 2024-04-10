#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
#define int long long


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < m; i++){
		cin >> b[i]; 
	}
	vector <int> d, a1, b1;
	int an = 0;
	int mx = 0; 
	for (int i = 0; i < n; i++){
		if (a[i] == 1){
			an ++;
		}else{
			if (an){
				a1.push_back(an);
				mx = max(mx, an);
			}
			an = 0;
		}
		mx = max(mx, an);
	}
	if (a[n - 1] == 1){
		a1.push_back(an);
		mx = max(mx, an);
	}
	an = 0;
	for (int i = 0; i < m; i++){
		if (b[i] == 1)
			an++;
		else{
			if (an){
				b1.push_back(an);
				mx = max(mx, an);
				an = 0;
			}
		}
		mx = max(mx, an);
	}
	if (b[m - 1] == 1){
		b1.push_back(an);
		mx = max(an, mx);
	}
//	cerr << mx << endl;
//	for (int i = 0; i < a1.size(); i++){
//		cerr << a1[i] << ' ';
//	}
//	cerr << endl;
//	for (int i = 0; i < b1.size(); i++){
//		cerr << b1[i] << ' ';
//	}
//	cerr << endl;
	for (int i = 1; i <= min({k, max(n, m)}); i++){
		if (k % i == 0 && k / i <= max(n, m)){
			d.push_back(i);
//			cerr << i << ' ';
		}
	}
//	cerr << endl;
	int ansa = 0;
	for (int i = 0; i < d.size(); i++){
		int ans = 0;
		int d1 = k / d[i];
		for (int j = 0; j < a1.size(); j++){
			if (a1[j] >= d[i]){
				ans += a1[j] - d[i] + 1;
			}
		}
		int ans2 = 0;
		for (int j = 0; j < b1.size(); j++){
			if (b1[j] >= d1){
				ans2 += b1[j] - d1 + 1;
			}
		}
		ansa += ans * ans2;
	}
	cout << ansa;
}