#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
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
typedef pair<int, int> pii;

const int module = 1e9+7;

int binPow(int base, int pow)
{
	if (pow==0)
		return 1;
	if (pow%2==1)
		return (1LL*base*binPow(base,pow-1))%module;
	int x = binPow(base,pow/2);
	return (1LL*x*x)%module;
}

int fact[1000001];

void precalc()
{
	fact[0] = 1;
	for (int i=1; i<=1000000; i++)
		fact[i] = (1LL*i*fact[i-1])%module;
}

int C(int n, int k)
{
	int res = fact[n];
	
	int d1 = fact[k];
	int d2 = fact[n-k];
	
	d1 = binPow(d1, module-2);
	d2 = binPow(d2, module-2);

	res = (1LL*d1*res)%module;
	res = (1LL*d2*res)%module;
	
	return res;
}

int a,b,n;

int good(int x)
{
	while (x)
	{
		if (x%10!=a && x%10!=b)
			return 0;
		x /= 10;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	precalc();
	int ans = 0;
	cin >> a >> b >> n;
	for (int i=0; i<=n; i++)
		if (good(a*i+b*(n-i)))
			ans = (ans + C(n,i))%module;
	cout << ans << endl;
	return 0;
}