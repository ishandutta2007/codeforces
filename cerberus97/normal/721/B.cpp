#include <iostream>

using namespace std;

string a[105], pw;

int main()
{
	int n, k;
	cin >> n >> k;

	int a1 = 0, a2 = -1;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> pw;

	for (int i = 0; i < n; ++i)
	{
		if (a[i].length() < pw.length())
		{
			++a1;
			++a2;
		}

		else if (a[i].length() == pw.length())
			++a2;
	}

	cout << (a1/k)*5 + a1 + 1 << ' ' << (a2/k)*5 + a2 + 1;
}