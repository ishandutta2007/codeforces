#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << "2\n";

	for (long long i = 2; i <= n; ++i)
		cout << i*i*i + 2*i*i + 1 << '\n';
}