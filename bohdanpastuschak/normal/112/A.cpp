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
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] <= 90)a[i] += 32;
	}
	for (int i = 0; i < b.length(); ++i)
	{
		if (b[i] <= 90)b[i] += 32;
	}

	if (a == b) cout << 0;
	else
		if (a > b) cout << 1;
		else cout << -1;
	return 0;
}