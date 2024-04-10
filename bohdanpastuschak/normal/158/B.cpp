#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (v[i] == 1) n1++;
		if (v[i] == 2) n2++;
		if (v[i] == 3) n3++;
		if (v[i] == 4) n4++;
	}
	int a = n4 + n3;
	if (n1 >= n3) n1 -= n3;
	else n1 = 0;
	if (n2 % 2 == 0)
	{
		a += n2 / 2;
		a += (n1 + 3) / 4;
	}
	else
	{
		a += (n2 + 1) / 2;
		a += (n1 + 1) / 4;
	}
	cout << a;

	return 0;
}