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
int n,i,j;
bool ispri(int x)
{
	if (x==1) return 0;
	int i;
	for (i=2;i*i<=x;i++) if (!(x%i)) return 0;
	return 1;
}
int main()
{
	cin>>n;
	if (ispri(n)) {cout<<"1\n"<<n;return 0;}
	if (ispri(n-2)) {cout<<"2\n2 "<<n-2;return 0;}
	for (i=n;!ispri(i);i--);
	cout<<"3\n"<<i;
	n-=i;
	for (i=2;i*2<=n;i++)
	{
		if (ispri(i)&&ispri(n-i)) {cout<<' '<<i<<' '<<n-i;return 0;}
	}
}