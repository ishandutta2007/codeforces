#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int ans[1001] = {};
		int x = 0;
		pair <int, int> a[n];
		for (int i = 0 ; i < n; i++){
			cin >> a[i].F;
			a[i].S = i;
		}
		int N = sqrt (1000) + 10;
		for (int i = 2; i < N; i++){
			if (ans[i])
				continue;
			x ++;
			for (int j = i * i; j <= 1000; j += i){
				if (ans[j] == 0)
					ans[j] = x;
			}
		}
		vector <pair <int, int>> vec;
		for (int i = 0; i < n; i++){
			vec.push_back({ans[a[i].F], i});
		}
		sort (vec.begin(), vec.end());
		int y = 1;
		for (int i = 0; i < n - 1; i++){
			if (vec[i].F != vec[i + 1].F){
				ans[vec[i].S] = y;
				y++;
			}else{
				ans[vec[i].S] = y;
			}
		}
		ans[vec[n - 1].S] = y;
		cout << y << endl;
		for (int i = 0; i < n; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}