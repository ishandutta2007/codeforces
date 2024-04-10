#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	cout << fixed << setprecision(12);
	ld a, b, c;	cin >> a >> b >> c;
	ld x, y;
	ld d = b * b - 4 * a * c;
	
	x = (-b + sqrt(d))/(a*2.0);
	y = (-b - sqrt(d))/(a*2.0);
	if (x < y)	swap(x, y);
	cout << x << "\n";
	cout << y << "\n";
	return	0;	
}