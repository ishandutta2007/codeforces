#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		v[i] = pair<int, int>(a, b);
	}

	int max = 0;
	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		if (max < counter)
			max = counter;
		counter -= v[i].first;
		if (max < counter)
			max = counter;
		counter += v[i].second;
		if (max < counter)
			max = counter;

	}

	cout << max;

	return 0;
}