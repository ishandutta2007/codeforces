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
#include <cassert>
#include <deque>
#include <memory.h>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <stack>
#include <utility>
#include <complex>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
#define male -mod
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (int i = (b-1); i>=(a); --i)

int main()
{	
	int n;
	cin >> n;
	
	vector<int> a(n);
	FOR(i,0,n)
		cin >> a[i];

	int max1= -1;
	FOR(i, 0, n)
	{
		FOR(j, i, n)
		{
			auto b = a;
			FOR(k, i, j + 1)
				b[k] = 1 - b[k];
			int num1 = 0;
			FOR(k, 0, n)
				if (b[k] == 1) num1++;

			max1 = max(max1, num1);
		}
	}
	cout << max1;
	return 0;
}