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
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		int i1, i2, i3;
		cin >> i1 >> i2 >> i3;
		v[i].push_back(i1);
		v[i].push_back(i2);
		v[i].push_back(i3);
	}
	int a = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i][0] + v[i][1] + v[i][2] > 1) a++;
	}
	cout << a;
	return 0;
}