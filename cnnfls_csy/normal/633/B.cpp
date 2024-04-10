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
int n,i,x;
int main()
{
	cin>>n;
	for (i=5;n>0;i+=5)
	{
		x=i;
		while (!(x%5)) {n--;x/=5;}
	}
	i-=5;
	if (n) cout<<0;
	else
	{
		cout<<5<<endl<<i<<' '<<i+1<<' '<<i+2<<' '<<i+3<<' '<<i+4;
	}
	return 0;
}