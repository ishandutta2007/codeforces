/* Codeforces 420
 *
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<int> Vint;

ll llmax(ll a, ll b)
{
	return (a < b ? b : a);
}

ll calc(ll x, ll y)
{
	ll val;
	if(x%2 == 1)
	{
		val = (x+1)/2;
		val *= (y+1)*(x+y);
	}
	else if(y%2 == 1)
	{
		val = (y+1)/2;
		val *= (x+1)*(x+y);
	}
	else
	{
		val = (x+y)/2;
		val *= (x+1)*(y+1);
	}
	return val;
}

ll m, b;

int main()
{
	cin >> m >> b;
	// x = -my + mb
	ll xval = 0, yval = 0;
	xval = m*b;
	ll maximum = 0;
	while(xval > 0)
	{
		maximum = llmax(maximum, calc(xval, yval));
		++yval;
		xval -= m;
	}
	
	cout << maximum << endl;

	return 0;
}