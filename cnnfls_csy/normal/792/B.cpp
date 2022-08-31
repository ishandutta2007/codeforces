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
int n,k,now,i,j,nex,step[105],chird[105];
int main()
{
	cin>>n>>k;
	for (i=1;i<=n;i++) chird[i]=i;
	for (i=1;i<=k;i++) cin>>step[i];
	for (i=1;i<=k;i++)
	{
		now=now%n;
		nex=(now+step[i])%n;
		cout<<chird[nex]+1<<' ';
		for (j=nex;j<n;j++) chird[j]=chird[j+1];
		n--;
		now=nex;
	}
	return 0;
}