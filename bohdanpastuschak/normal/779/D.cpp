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

string t, p;
vector<bool> isNow;
vector<int> a;

bool canInThis(int index)
{
	for (int i = 0; i <= index; ++i)
		isNow[a[i]] = false;

	int inP = 0;
	bool iss = false;
	for (int i = 0; i < t.length(); ++i)
	{
		if (isNow[i] && t[i] == p[inP])
		{
			inP++;
		}
		if (inP >= p.length())
		{
			iss = true;
			break;
		}
	}

	for (int i = 0; i <= index; ++i)
		isNow[a[i]] = true;

	if (iss) return true;
	return false;

}

int findFirstInRange(int left, int right)
{
	if (right == left) return left;
	if (right - left == 1)
	{
		if (!canInThis(left)) return left;
		else return right;
	}
	
	int med = (left + right) / 2;
	if ((canInThis(med)))
	{
		return findFirstInRange(med+1, right);
	}
	else
		return findFirstInRange(left, med);
}

int solve()
{
	return (findFirstInRange(0, t.length() - 1));
}

int main()
{
	
	cin >> t >> p;
	int buff;
	for (int i = 0; i < t.size(); ++i)
	{
		cin >> buff;
		a.push_back(buff - 1);
	}


	for (int i = 0; i < t.length(); ++i)
	{
		isNow.push_back(true);
	}

	cout << solve();	
	return 0;
}