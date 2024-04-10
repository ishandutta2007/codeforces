#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int a, b;
	cin >> a >> b;
	int a1 = 7 - max(a, b);
	cout << a1/__gcd(a1, 6) << '/' << 6 / __gcd(6, a1);
}