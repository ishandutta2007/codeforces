#include<algorithm>
#include<iostream>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int a[100001],x[4];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		x[a[i]-1]++;
	}
	int ans=x[3];//4 4 3 3 2 2 1 1
	if(x[2]>=x[0])
	{
		ans+=x[2];
		x[0]=0;
	}
	else
		ans+=x[2],
		x[0]-=x[2];
	if((x[0]*1+x[1]*2)%4!=0)
		ans+=(x[0]*1+x[1]*2)/4+1;
	else
		ans+=(x[0]*1+x[1]*2)/4;
	cout<<ans;
}