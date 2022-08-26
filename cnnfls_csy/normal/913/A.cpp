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
int n,m,i,j,s=1;
int main()
{
	cin>>n>>m;
	while (n--)
	{
		s*=2;
		if (s>m) break;
	}
	cout<<m%s;
	return 0;
}