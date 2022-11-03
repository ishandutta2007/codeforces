#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int module = 1e9+7;

int binPow(int base, int pow)
{
	if (pow==0)
		return 1;
	if (pow%2==1)
		return (1LL*base*binPow(base, pow-1))%module;
	int x = binPow(base,pow/2);
	return (1LL*x*x)%module;
}

int n,m;
vector<int> a;


int main()
{
	cin >> n >> m;
	a.resize(n);
	for (int i=0; i<m; i++)
	{
		int x;
		cin >>x;
		x--;
		a[x]=1;
	}
	int res=1;
	for (int i=2; i<=n-m; i++)
		res = (1LL*res*i)%module;
	int d=1;
	int c=0;
	int st=0;
	int start=1;
	for (int i=0; i<n; i++)
		if (a[i])
		{
			if (!start && c > 0)
				st += c-1;
			for (int j=1; j<=c; j++)
				d = (1LL*d*j)%module;
			c = 0;
			start=0;
		}else
			c++;
	for (int j=1; j<=c; j++)
		d = (1LL*d*j)%module;
	res = (1LL*res*binPow(2,st))%module;
	d = binPow(d, module-2);
	res = (1LL*res*d)%module;
	cout << res << endl;
	return 0;
}