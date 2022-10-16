#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << (1 << __builtin_popcount(n)) << endl;
	}
}