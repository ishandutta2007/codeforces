#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int x = sqrt(a * c / b);
	int y = a / x;
	int z = c / x;
	cout << 4 * (x + y + z);
	//xy yz xz
}