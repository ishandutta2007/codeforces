/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
pair <int, pair <bool, bool>> a[N];
bool h[N];

int32_t main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S.F >> a[i].S.S;
	sort (a, a + n);
	vector <ll> v[2][2];
	for (int i = 0; i < n; i++){
		v[a[i].S.F][a[i].S.S].push_back(a[i].F);
	}
	ll ans = 0;
	v[0][0].clear();
	for (int i = 0; i < min(v[0][1].size(), v[1][0].size()); i++){
		v[0][0].push_back(v[1][0][i] + v[0][1][i]);
	}
	if (v[1][1].size() + v[0][0].size() < k){
		cout << -1;
		return 0;
	}
	sort (v[0][0].begin(), v[0][0].end());
	sort (v[1][1].begin(), v[1][1].end());
	reverse (v[0][0].begin(), v[0][0].end());
	reverse (v[1][1].begin(), v[1][1].end());
//	cerr << v[0][0].back() << endl;
//	cerr << v[1][1].back() << endl;
	for (int i = 0; i < k; i++){
		if (v[0][0].empty ()){
			ans += v[1][1].back();
			v[1][1].pop_back();
		}else if (v[1][1].empty ()){
			ans += v[0][0].back();
			v[0][0].pop_back();
		}else if (v[0][0].back() > v[1][1].back()){
			ans += v[1][1].back();
			v[1][1].pop_back();
		}else{
			ans += v[0][0].back();
			v[0][0].pop_back();
		}
	}
	cout << ans;
}