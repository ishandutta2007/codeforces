#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (m * a <= b)
		cout << n * a;
	else{
		cout << n / m * b + min(n % m * a, b);
	}
}