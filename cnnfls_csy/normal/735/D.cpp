#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n;
bool ispri(int x)
{
	int i;
	for (i=2;i*i<=x;i++)
	{
		if (!(x%i)) return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	if (ispri(n)) cout<<1;
	else if (ispri(n-2)||!(n%2)) cout<<2;
	else cout<<3;
	return 0;
}