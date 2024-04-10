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

bool divis(int n, int k)
{
	if (n % (ll)(pow(10, k)) != 0) return false;
	return true;
}

int main()
{
	string n;
	cin >> n;
	int k;
	cin >> k;
	int ans = 0;
	int zer = 0;
	for (int i = n.length() - 1; i >= 0; --i)
	{
		if (zer >= k) break;
		if (n[i] == '0')zer++;
		else ans++;
	}
	if (zer < k)
	{
		cout << n.length() - 1;
	}
	else	cout << ans;
	return 0;
}