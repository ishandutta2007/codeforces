#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include <fstream>
#include <map>
using namespace std;
#define ll unsigned long long

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());

	int least = 1000;
	for (int i = 0; i < m - n + 1; ++i)
	{
		if (least > a[n + i - 1] - a[i])
			least = a[n - 1 + i] - a[i];
	}

	cout << least;
	return 0;
}