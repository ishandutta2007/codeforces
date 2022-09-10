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
	int x = 0;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (v[i][0] == '+' || v[i][2] == '+')
			++x;
		else
			--x;
	}

	cout << x;
	return 0;
}