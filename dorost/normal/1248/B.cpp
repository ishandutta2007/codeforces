#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	ll sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++){
		if(i < n / 2){
			sum1 += a[i];
		}else
			sum2 += a[i];
	}
	cout << sum1 * sum1 + sum2 * sum2 << endl;
}