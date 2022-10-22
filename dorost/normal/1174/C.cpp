#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int32_t main(){
	ios::sync_with_stdio(0);
 	int n;
	cin >> n;
	int a[n + 1];
	bool f[n + 1] = {};
	for (int i = 0; i < n + 1; i++)
		a[i] = -1;
	int x = 1;
	for (int i = 2; i <= n + 4; i++){
		if (f[i])
			continue;
		for (int j = i; j <= n + 5; j += i){
			if (a[j] == -1)
				a[j] = x;
			f[j] = true;
		}
		x++;
	}
	for (int i = 2; i <= n; i++){
		cout << max(1, a[i]) << ' ';
	}
}