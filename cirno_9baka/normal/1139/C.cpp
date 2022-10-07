#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=1000000007;
int n,i,k,u,v,w,f[100005],s[100005];
long long ans;
int Find(int x)
{
	if(f[x]==0)
		return x;
	return f[x]=Find(f[x]);
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[x]=y;
}
long long qpow(int a,int b)
{
	long long s=1;
	while(b--)
		s=s*a%M;
	return s;
}
int main(){
	scanf("%d %d",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		if(w==0)
			uniot(u,v);
	}
	for(i=1;i<=n;i++)
		s[Find(i)]++;
	for(i=1;i<=n;i++)
		if(f[i]==0)
			ans=(ans+qpow(s[i],k))%M;
	cout<<((qpow(n,k)-ans)%M+M)%M;
}