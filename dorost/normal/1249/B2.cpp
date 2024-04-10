/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], ansa[N];
bool f[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			a[i] --;
			f[i] = false;
		}
		for (int i = 0; i < n; i++){
			if (f[i])
				continue;
			int x = i;
			int y = i;
			vector <int> v;
			int ans = 0;
			f[i] = true;
			while (y != x || ans == 0){
				v.push_back(y);
				y = a[y];
				f[y] = true;
				ans ++;
			}
			for (int i = 0; i < v.size(); i++){
				ansa[v[i]] = ans;
			}
		}
		for (int i = 0; i < n; i++){
			cout << ansa[i] << ' ';
		}
		cout << endl;
	}
}