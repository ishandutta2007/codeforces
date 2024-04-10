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

string maxi(int m, int s)
{
	string toR;
	if (s < 10)
	{
		toR += (s + 48);
		FOR(i, 0, m - 1)
			toR += '0';
		return toR;
	}
	return '9' + maxi(m - 1, s - 9);
}

string mini(int m, int s)
{
	string toR;

	FOR(i, 0, m)
		toR += '0';

	int index = m - 1;
	while (index >= 0)
	{
		if (s <= 0) break;
		if (s < 10) {
			toR[index] = (s + 48);
			s = 0;
		}
		else
		{
			s -= 9;
			toR[index] = '9';
		}

		--index;
	}
	if (toR[0] == '0')
	{
		FOR(i,1,m)
			if (toR[i] != '0')
			{
				toR[0] = '1';
				toR[i] -= 1;
				break;
			}
	}
	return toR;
}

int main()
{	
	int m, s;
	cin >> m >> s;
	if (m == 1 && s == 0)
	{
		cout << "0 0";
		return 0;
	}
	if (s == 0 || s > 9*m)
	{
		cout << "-1 -1";
		return 0;
	}

	cout << mini(m, s) << " " << maxi(m, s);
	return 0;
}