#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int p;

bool check(int x)
{
	x %= p;
	int y=1;
	for (int i=1; i<=p-2; i++)
	{
		y=(y*x)%p;
		if (y==1)return 0;
	}
	y=(y*x)%p;
	if (y!=1)return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> p;
	int ans=0;
	for (int i=1; i<p; i++)
		if (check(i))
			ans++;
	cout << ans << endl;
	return 0;
}