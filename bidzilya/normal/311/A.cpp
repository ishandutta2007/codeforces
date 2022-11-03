#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,k;
	cin >> n >> k;
	int maxtot = n*(n-1)/2;
	if (maxtot <= k)
	{
		cout << "no solution" << endl;
		return 0;
	}
	int y = 1000*1000*1000;
	for (int i=0; i<n; i++, y -= 1000000)
		cout << i << " " << y << endl;
	return 0;
}