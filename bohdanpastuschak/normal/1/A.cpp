#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
	long long n, m, a,x,y;
	cin >> n >> m >> a;

	if (n%a == 0)
		x = n / a;
	else
		x = n / a + 1;

	if (m%a == 0)
		y = m / a;
	else
		y = m / a + 1;

	cout << x*y;
	return 0;
}