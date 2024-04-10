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
using namespace std;

int main()
{
	string s;
	cin >> s;

	int a[7];
	for (int i = 0; i < 7; ++i)
	{
		a[i] = 0;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == 'B')
			a[0]++;
		if (s[i] == 'u')
			a[1]++;
		if (s[i] == 'l')
			a[2]++;
		if (s[i] == 'b')
			a[3]++;
		if (s[i] == 'a')
			a[4]++;
		if (s[i] == 's')
			a[5]++;
		if (s[i] == 'r')
			a[6]++;		
	}

	int min = 100000;
	if (a[0] < min) min = a[0];
	if (a[2] < min) min = a[2];
	if (a[3] < min) min = a[3];
	if (a[5] < min) min = a[5];
	if (a[6] < min) min = a[6];

	if ( min > a[1]/2) min = a[1] / 2;
	if ( min > a[4]/2) min = a[4] / 2;

	cout << min;
	return 0;
}