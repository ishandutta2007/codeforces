#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PP = 3.14159265358979323846264338327950;

int main(){
	cout << fixed << setprecision(12);
	ld a, b, c;	cin >> a >> b >> c;
	
	ld aa = (ld)sqrt(3)/ (ld)2.0 * a;
	ld hh = aa;
	aa = ld(2.0/ (ld)3.0) * aa;
	ld ha = sqrt(a * a - aa * aa);
	a = a * hh * (ld)0.5;
	a = a / (ld)3.0 * ha;
	
	
	ld bb = (ld)sqrt(b * b + b * b) / (ld)2.0;
	ld hb = (ld)sqrt(b * b - bb * bb);
	b = hb/(ld)3.0 * b * b;


	ld cc = c/ ld(2.0 * (ld)sin(PP/5.0));
	ld hc = cc * ld(1.0 + (ld)cos(PP/5.0));
	ld s = (ld)2.5 * c * (hc - cc);
	cc = sqrt(c * c - cc * cc);
	c = cc * s / (ld)3.0;

	cout << a + b + c << "\n";
	return	0;
}