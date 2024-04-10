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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int max = 0;
	int curr = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i + 1] >= a[i])
			curr++;
		else
		{
			if (max < curr)
			{
				max = curr;
			}
			curr = 1;
		}
	}
	if (max < curr) max = curr;
	cout << max;
	return 0;
}