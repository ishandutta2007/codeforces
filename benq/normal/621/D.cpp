#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int main() {
	ld x,y,z, maxvalue, minindex;
	cin >> x >> y >> z;
	maxvalue = x*y*log(z);
	minindex = 11;

	if (pow(y,x)*log(z)>=maxvalue) {
		maxvalue = pow(y,x)*log(z);
		minindex = 10;
	}
	if (pow(x,y)*log(z)>=maxvalue) {
		maxvalue = pow(x,y)*log(z);
		minindex = 9;
	}
	if (x*z*log(y)>=maxvalue) {
		maxvalue = x*z*log(y);
		minindex = 7;
	}
	if (pow(z,x)*log(y)>=maxvalue) {
		maxvalue = pow(z,x)*log(y);
		minindex = 6;
	}
	if (pow(x,z)*log(y)>=maxvalue) {
		maxvalue = pow(x,z)*log(y);
		minindex = 5;
	}
	if (y*z*log(x)>=maxvalue) {
		maxvalue = y*z*log(x);
		minindex = 3;
	}
	if (pow(z,y)*log(x)>=maxvalue) {
		maxvalue = pow(z,y)*log(x);
		minindex = 2;
	}
	if (pow(y,z)*log(x)>=maxvalue) {
		maxvalue = pow(y,z)*log(x);
		minindex = 1;
	}
	
	if (minindex == 11) cout << "(z^x)^y";
	if (minindex == 10) cout << "z^y^x";
	if (minindex == 9) cout << "z^x^y";
	if (minindex == 7) cout << "(y^x)^z";
	if (minindex == 6) cout << "y^z^x";
	if (minindex == 5) cout << "y^x^z";
	if (minindex == 3) cout << "(x^y)^z";
	if (minindex == 2) cout << "x^z^y";
	if (minindex == 1) cout << "x^y^z";
	return 0;
}