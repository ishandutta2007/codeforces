#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

int main(){
	cout << fixed << setprecision(12);
	ll a, aa, b, bb, c, cc;
	cin >> a >> b >> c;
	cin >> aa >> bb >> cc;
	if (c < cc)
		swap(a, aa), swap(b, bb), swap(c, cc);

	ld dis = sqrt((a - aa) * (a - aa) + (b - bb) * (b - bb));
	if (dis - c - cc > 0)
		cout << (dis - c - cc)/ ld(2) << "\n";
	else if (c > dis + cc)
		cout << (c - dis - cc)/ ld(2) << "\n";
	else
		cout << "0\n";
	return	0;
}