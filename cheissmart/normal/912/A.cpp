#include <iostream>

using namespace std;

int main()
{
	long long a, b, x, y, z, ct = 0;
	cin >> a >> b >> x >> y >> z;
	a -= 2 * x;
	a -= y;
	b -= y;
	b -= 3 * z;
	if(a < 0) ct -= a;
	if(b < 0) ct -= b;
	cout << ct << endl;
}