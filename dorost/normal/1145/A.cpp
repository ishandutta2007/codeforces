#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n; i > 1; i /= 2){
		for (int j = 0; j <= n - i; j += i){
			if (is_sorted(a + j, a + j + i)){
				cout << i;
				return 0;
			}
		}
	}
	cout << 1;
}