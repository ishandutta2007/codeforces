#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int s = 0;
	bool isNonZero = false;
	int ind = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		s += v[i];
		if (v[i] != 0 && !isNonZero)
		{
			isNonZero = true;
			ind = i;
		}
	}

	if (s != 0)
	{
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << " " << n;
	}
	else
	{
		if (!isNonZero)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES" << endl << 2 << endl;
			cout << 1 << " " << ind + 1 << endl << ind + 2 << " " << n;
		}

	}

	return 0;
}