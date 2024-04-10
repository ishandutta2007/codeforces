#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int a[n], ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	for (int i = 0; i < n; i++){
		a[i] *= a[i];
		if (i % 2){
			ans -= a[i];
		}else{
			ans += a[i];
		}	
	}
	cout << abs(ans) *  3.1415926536;
}