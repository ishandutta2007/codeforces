/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector <int> v1, v2;
		for (int i = 0; i < n * 2; i++){
			cin >> a[i];
			if (a[i] % 2)
				v1.push_back(i + 1);
			else
				v2.push_back(i + 1);
		}
		vector <pair <int, int>> ans;
		for (int i = 0; i < (int)v1.size() / 2 * 2; i += 2){
			ans.push_back({v1[i], v1[i + 1]});
		}
		for (int i = 0; i < (int)v2.size() / 2 * 2; i += 2){
			ans.push_back({v2[i], v2[i + 1]});
		}
		while (ans.size() != n - 1){
			ans.pop_back();
		}
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i].F << ' ' << ans[i].S << endl;
		}
	}
}