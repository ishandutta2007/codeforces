#include <iostream>
#include <algorithm>

using namespace std;

int a[(int)3e5];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	cout << a[(n-1)/2];
}