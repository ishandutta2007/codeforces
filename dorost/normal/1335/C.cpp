#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 212345;
int a[N], mp[N];

int32_t main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++)
			mp[i] = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]] ++;
		}
		int mx = 0, sum = 0;
		for (int i = 1; i <= n; i++){
			if (mp[i] > mx){
				mx = mp[i];
			}
		}
		bool f = true;
		for (int i = 1; i <= n; i++){
			if (mp[i] == mx && f){
				f = false;
				continue;
			}
			if (mp[i])
				sum ++;
		}
		if (mx == 1){
			if (n == 1)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}else if (mx == sum){
			cout << mx << endl;
		}else if(sum > mx){
			cout << mx << endl;
		}else if (mx > sum + 1){
			cout << sum + 1 << endl;
		}else if (mx == sum + 1){
			cout << sum << endl;
		}
	}
}