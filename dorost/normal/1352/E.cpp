/*	* In the name of GOD
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 8001;
int a[N];
bool mp[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			mp[i] = false;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			int ans = a[i];
			for (int j = i + 1; j < n; j++){
				ans += a[j];
				if (ans > n)
					break;
				mp[ans] = true;
			}
		}
		int ansa = 0;
		for (int i = 0; i < n; i++){
			if (mp[a[i]])
				ansa ++;
		}
		cout << ansa << '\n';
	}
}