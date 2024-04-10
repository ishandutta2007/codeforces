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
int n,lo,now,i,t,mi=1<<25,j,x;
bool bo[100005];
int main()
{
	cin>>n>>now>>lo;
	while ((now-lo)%50) lo++;
	for (i=lo;i<=100000;i+=50)
	{
		//cerr<<i<<endl;
		t=i/50%475;
		for (j=1;j<=25;j++)
		{
			//cerr<<j<<' '<<t<<';';
			t=(t*96+42)%475;
			if (26+t==n) {bo[i]=1;cerr<<i<<endl;}
		}
	}
	for (i=lo;i<=100000;i+=50)
	{
		//cerr<<i;
		if (bo[i])
		{
			mi=min(mi,max(0,(i-now+50)/100));
		}
	}
	cout<<mi;
	return 0;
}