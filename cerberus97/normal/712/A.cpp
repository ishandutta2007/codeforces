#include <iostream>

using namespace std;

const int N = int(1e5) + 5;

long long a[N], b[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	b[n-1] = a[n-1];

	for (int i = 0; i < n-1; ++i)
		b[i] = a[i] + a[i+1];

	for (int i = 0; i < n; ++i)
		cout << b[i] << ' ';
}