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
		int n, k, ans = 0;
		cin >> n >> k;
		string s;
		cin >> s; 
		for (int i = 0; i < (k + 1) / 2; i ++){
			int a[26] = {};
			for (int j = i; j < n; j += k){
				a[s[j] - 'a'] ++;
				int y = j / k * k;
				int x = j / k * k + k - 1;
				if (x - (j - y) != j)
					a[s[x - (j - y)] - 'a'] ++;
				//cout << "#" << x - 1 - j + y << endl;
			}
			int mx = 0, sum = 0;
			for (int j = 0; j < 26; j++){
				mx = max(mx, a[j]);
				sum += a[j];
			}
			ans += sum - mx;
		}
		cout << ans << endl;
	}
}