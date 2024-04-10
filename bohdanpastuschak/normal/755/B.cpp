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
	int n, m;
	cin >> n >> m;
	vector<string> v1(n);
	vector<string> v2(m);
	for (int i = 0; i < n; ++i)
		cin >> v1[i];
	for (int i = 0; i < m; ++i)
		cin >> v2[i];
	
	int common = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			if (v1[i] == v2[j])
				common++;
	}

	if (common % 2 == 0)
	{
		if (n <= m)
			cout << "NO";
		else
			cout << "YES";
	}
	else
	{
		if (n < m)
			cout << "NO";
		else
			cout << "YES";
	}

	return 0;
}