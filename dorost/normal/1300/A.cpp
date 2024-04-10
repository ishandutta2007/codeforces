#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		int ans = 0, sum = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] == 0){
				a[i] = 1;
				ans ++;
			}
			sum += a[i];
		}
		cout << ans + (sum == 0) << endl;
	}
}