#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll a, b, c, d;	cin >> a >> b >> c >> d;
	a = max(75 * a, 250 * a - a * c);
	b = max(75 * b, 250 * b - b * d);
	if (a > b)
		cout << "Misha\n";
	if (b > a)
		cout << "Vasya\n";
	if (a == b)
		cout << "Tie\n";
	return	0;
}