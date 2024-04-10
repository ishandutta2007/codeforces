#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	ld sum = 0;
	for (int i = 1; i <= n; i++){
		sum += 1.0 / i;
	}
	cout << fixed << setprecision(4);
	cout << sum;
}