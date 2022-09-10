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
	long long n;
	cin >> n;

	long long* a = new long long[n];
	long long max = 0;
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
	}

	long long s = 0;
	for (long long i = 0; i < n; ++i)
	{
		s += (max - a[i]);
	}
	cout << s;
	return 0;
}