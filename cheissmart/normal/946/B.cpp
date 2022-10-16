#include <iostream>
#define int long long
using namespace std;

signed main()
{
	int a, b;
	cin >> a >> b;
	while(true) {
		if(a == 0 || b == 0) break;
		if(a >= 2*b) {
			a %= 2*b;
			continue;
		}
		if(b >= 2*a)  {
			b %= 2*a;
			continue;
		}
		else break;
	}
	cout << a << " " << b << endl;
}