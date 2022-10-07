#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
int n,m,k,f[200005],s,i;
struct str{
	int a,x;
}a[200005];
long long ans=0;
bool cmp(str a,str b)
{
	return a.a>b.a;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].x=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=m*k;i++)
	{
		ans+=a[i].a;
		f[a[i].x]=1;
	}
	cout<<ans<<endl;
	for(i=1;i<=n;i++)
	{
		s+=f[i];
		if(s==m&&k!=1)
		{
			s=0;
			k--;
			printf("%d ",i);
		}
	}
}