#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,i,a,b,f[500005],s,mx,o;
long long ans;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d %d %d",&n,&a,&b);
	int g=gcd(a,b);
	o=n;
	n/=g;
	a/=g;
	b/=g;
	i=a;
	mx=a;
	while(1)
	{
		while(i>=b)
		{
			i-=b;
			f[i]=mx;
		}
		mx=max(mx,i+a);
		if(i==0)
			break;
		i+=a;
	}
	f[0]=0;
	for(i=a;i<mx&&i<=n;i++)
		f[i]=max(i,f[i-a]);
	for(i=0;i<mx&&i<=n;i++)
		if(f[i]<=n)
			ans+=o-f[i]*g+1;
	if(n>=mx)
		cout<<ans+1ll*o*(n-mx+1)-1ll*g*(mx+n)*(n-mx+1)/2+n-mx+1;
	else
		cout<<ans;
}