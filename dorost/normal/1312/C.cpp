#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
#define int unsigned long long

int32_t main(){
	ios::sync_with_stdio(false);
	int32_t t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		vector <int> vec;
		map <int, bool> v;
		bool h = true;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			//cout << "#" << v[i] << endl;
			while (h){
				int ans;
				for (ans = 1;ans <= a[i]; ans *= k);
				ans /= k;
				if (ans == 0 || a[i] == 0){
					break;
				}else{
					if (v[ans]){
						h = false;
					}
					vec.push_back(ans);
					v[ans] = true;
				}
				a[i] -= ans;
			}
		}
		bool f1[1234] = {};
		for (int i = 0; i < vec.size() && h; i++){
			bool f = false;
			int poww = 1;
			for (int j = 0; poww <= vec[i]; j++){
			//	cout << poww(k, j) << endl;
				if (vec[i] == poww && f1[j] == false){
					f = true;
					f1[j] = true;
					break;
				}
				poww = (poww * k);
			}
			if (!f){
				h = false;
				break;
			}
		}
		hoy :
		cout << (h ? "YES" : "NO") << endl;
	}
}