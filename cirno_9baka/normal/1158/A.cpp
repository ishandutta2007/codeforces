#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i,m,a[200005],b[200005];
ll ans;
int main(){
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(b[1]<a[n])
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=n;i++)
		ans+=1ll*a[i]*m;
	for(i=2;i<=m;i++)
		ans+=b[i]-a[n];
	if(a[n]==b[1])
	{
		cout<<ans<<endl;
		return 0;
	}
	else
		cout<<ans+b[1]-a[n-1];
}