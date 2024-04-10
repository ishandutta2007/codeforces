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
	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0)
	{
		cout << "NO";
		return 0;
	}
	if (abs(a - b) <= 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}