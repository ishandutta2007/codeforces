#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;

int main(){
	ld l, a, b;	cin >> l >> a >> b;
	ld s = (a + b);
	s = l/ s;
	cout << fixed << setprecision(12);
	cout << a * s << "\n";
	return	0;
}