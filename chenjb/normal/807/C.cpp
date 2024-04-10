#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
	LL x,y,p,q;
void work()
{
	if (p==q)
	{
		if (x==y)cout<<0<<endl;
		else cout<<-1<<endl;
		return;
	}
	if (p==0)
	{
		if (x==0)cout<<0<<endl;
		else cout<<-1<<endl;
		return;
	}

	LL t2=p-q;
	LL t1=x-y;
	LL k1=t1/t2;
	if (t1%t2!=0)k1++;

	LL k2=x/p;
	if (x%p!=0)k2++;
	
	LL k3=y/q;
	if (y%q!=0)k3++;

	LL k=max(k1,max(k2,k3));
	cout<<k*q-y<<endl;
}
int main()
{
	int T;
	cin>>T;
	while (T--)
		{
			cin>>x>>y>>p>>q;
			work();
		}
	return 0;
}

/*
x/y

p/q

k*p-x<=k*q-y
k*(p-q)<=x-y

k*p>=x
k*q>=y;

k>=(x-y)/(p-q)
k>=x/p
k>=y/q

k
*/