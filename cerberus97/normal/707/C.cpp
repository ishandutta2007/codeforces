#include <iostream>

using namespace std;

int main()
{
	long long n, n2;
	cin >> n;
	n2 = n*n;

	if (n < 3)
		cout << -1;

	else if (n%2)
		cout << (n2 + 1)/2 << ' ' << (n2 - 1)/2;

	else
		cout << (n2 + 4)/4 << ' ' << (n2 - 4)/4;
}