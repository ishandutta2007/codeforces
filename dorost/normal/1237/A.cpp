#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int32_t main(){
	int n;
	cin >> n;
	int a[n];
	int x = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] % 2 == 0){
			cout << a[i] / 2;
		}else{
			cout << (a[i] - 1 + 2 * (x % 2 == 0)) / 2;
			x++;
		}
		cout << endl;
	}
}