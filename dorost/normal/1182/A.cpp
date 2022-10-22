#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	if (n % 2)
		cout << 0;
	else
		cout << (int)pow(2, n / 2);
}