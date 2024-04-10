#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, v, l, r;
		cin >> n >> v >> l >> r;
		int m = r/v;
		if(l % v == 0)
			l--;
		m -= l/v;
		cout << n/v - m << endl;
	}
}