#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

typedef long long ll;

ll n;
int k;

int main()
{
	cin >> n >> k;
	n--;k--;
	if (1LL*(k+1)*k/2<n)
	{
		cout << -1 << endl;
		return 0;
	}
	if (n==0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n<=k)
	{
		cout << 1 << endl;
		return 0;
	}
	int l=1,r=k;
	while (l<=r)
	{
		int m=(l+r)/2;
		ll t=1LL*(m+k)*(k-m+1)/2;
		if (t<n)
			r=m-1;
		else
		if (t>n)
			l=m+1;
		else
		{
			cout << k-m+1 << endl;
			return 0;
		}
	}
	cout << k-l+2 << endl;
	return 0;
}