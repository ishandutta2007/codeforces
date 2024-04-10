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
#include <map>
using namespace std;
#define ll long long

int main()
{
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	
	int a = 0;
	for (int i = 1; i <= d; ++i)
	{
		if (i%k != 0 && i%l != 0 && i%m != 0 && i%n != 0)a++;
	}

	cout << d - a;
	return 0;
}