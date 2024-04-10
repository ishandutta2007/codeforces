#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;

ld pw(ld a, int b){
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
	cout << fixed << setprecision(10);
	cin >> n >> m;

	ld last = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		ld p = pw(ld(i)/ ld(n), m) - last;
		ans += p * i;
		last += p;
	}
	cout << ans << endl;
	return	0;	
}