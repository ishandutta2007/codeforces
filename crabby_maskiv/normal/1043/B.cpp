#include<iostream>
#include<cstdio>
#define maxn 10005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m;
int a[maxn];
int x[maxn];
int cnt=1,vis[maxn];
int main()
{
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i-1]=a[i]-a[i-1];
	}
	vis[n]=1;
	for(i=1;i<n;i++)
	{
		bool flag=0;
		for(j=0;j<n;j++)
		{
			int k=j%i;
			if(x[j]!=x[k])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cnt++;
			vis[i]=1;
		}
	}
	cout<<cnt<<endl;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==1)
		    cout<<i<<" ";
	}
	return 0;
}