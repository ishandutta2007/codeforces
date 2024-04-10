#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	if (a.length() > b.length())
	{
		cout << a.length();
		return 0;
	}
	if (a.length() < b.length())
	{
		cout << b.length();
		return 0;
	}

	if (a == b)
	{
		cout << -1;
		return 0;
	}
	cout << a.length();

	


	return 0;
}