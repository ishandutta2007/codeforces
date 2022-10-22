#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

ld pw(ld a, ll b){
	ld ret = 1;
	while (b){
		if (b & 1)
			ret *= a;
		b >>= 1;
		a *= a;
	}
	return	ret;
}

int main(){
	cout << fixed << setprecision(12);
	ld n, t;	cin >> n >> t;
	n = n * pw(1.000000011, t);
	cout << n << "\n";
	return	0;
}