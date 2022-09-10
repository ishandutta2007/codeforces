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
	vector<int> p(n);
	int a = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		if (p[i] == i + 1)a++;
	}

	for (int i = 0; i < n; ++i)
	{
		if (p[p[i] - 1] == i+1) a++;
	}

	cout << a / 2;
	return 0;
}