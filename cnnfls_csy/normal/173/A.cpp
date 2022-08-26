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
string st1,st2;
long long n,m,i,j,w1,w2,l1,l2;
long long gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	cin>>n>>st1>>st2;
	m=st1.length()/gcd(st1.length(),st2.length())*st2.length();
	l1=st1.length();
	l2=st2.length();
	for (i=0;i<m;i++)
	{
		if (st1[i%l1]==st2[i%l2]) continue;
		if (st1[i%l1]=='R')
		{
			if (st2[i%l2]=='S') w1++;
			else w2++;
		}
		if (st1[i%l1]=='S')
		{
			if (st2[i%l2]=='P') w1++;
			else w2++;
		}
		if (st1[i%l1]=='P')
		{
			if (st2[i%l2]=='R') w1++;
			else w2++;
		}
	}
	w1*=n/m;
	w2*=n/m;
	for (i=0;i<n%m;i++)
	{
		if (st1[i%l1]==st2[i%l2]) continue;
		if (st1[i%l1]=='R')
		{
			if (st2[i%l2]=='S') w1++;
			else w2++;
		}
		if (st1[i%l1]=='S')
		{
			if (st2[i%l2]=='P') w1++;
			else w2++;
		}
		if (st1[i%l1]=='P')
		{
			if (st2[i%l2]=='R') w1++;
			else w2++;
		}
	}
	cout<<w2<<' '<<w1;
}