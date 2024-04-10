#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
#define male -mod

int main()
{	
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;

	int* solve = new int[n + 1];
	solve[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int t = male;
		if (i >= a)
		 t = max(t,solve[i - a]+1);
		if (i >= b)
			t = max(t, solve[i - b] + 1);
		if (i >= c)
			t = max(t, solve[i - c] + 1);
		solve[i] = t;
	}
	
	cout << solve[n];
	
	return 0;
}