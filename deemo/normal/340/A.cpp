#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

ll x, y, a, b;

int main(){
	cin >> x >> y >> a >> b;
	if (a > b){
		cout << 0 << endl;
		return 0;
	}
	int t = __gcd(x, y);
	x *= y;
	x /= t;
	cout << b / x - (a - 1) / x << endl;
	return 0;
}