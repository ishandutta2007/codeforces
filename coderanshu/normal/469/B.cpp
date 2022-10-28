#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m=0,t,l,r,p,q,temp1,temp2,count=0,i,j;
	cin>>p>>q>>l>>r;
	int a[1005],b[1005];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=0;i<p;i++)
	{
		cin>>temp1>>temp2;
		for(j=temp1;j<=temp2 && j<=1000;j++)
			a[j]=1;
	}
	for(i=0;i<q;i++)
	{
		cin>>temp1>>temp2;
		for(j=temp1+l;j<=temp2+l && j<=1000;j++)
			b[j]=1;
	}
	while(l<=r)
	{
		for(i=0;i<=1000;i++)
		{
			if(a[i] && b[i])
			{
				count++;
				break;
			}
		}
		l++;
		for(i=1000;i>0;i--)
			b[i]=b[i-1];
		b[0]=0;
	}
	cout<<count;
	return 0;
}