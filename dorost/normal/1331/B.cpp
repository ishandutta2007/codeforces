#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	for (int i = sqrt(n); i > 0; i--){
		if (n % i == 0){
			cout << i << n / i;
			break;
		}
	}
}