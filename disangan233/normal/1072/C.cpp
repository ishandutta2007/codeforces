#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll i,a,b,x,n,m,vis[1000005];
int main()
{
	cin>>a>>b;
	while(1LL*x*(x+1)/2<=a+b)x++;
	x--;
	for(ll i=x;i>=1;i--)
	if(a>=i)
	vis[i]=1,a-=i,n++;
	cout<<n<<endl;
	m=x-n;
	for(ll i=1;i<=x;i++)
	if(vis[i])
	printf("%d ",i);
	cout<<endl<<m<<endl;
	for(ll i=1;i<=x;i++)
	if(!vis[i])
	printf("%d ",i);
}