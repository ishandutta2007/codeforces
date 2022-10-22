#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;

ld d, l, v1, v2;

int main(){
	cout << fixed << setprecision(12);
	cin >> d >> l >> v1 >> v2;
	l -= d;
	cout << l/ (v1 + v2) << "\n";
	return	0;
}