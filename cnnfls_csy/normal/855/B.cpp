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
long long n,m,i,j,num[100005],p,q,x,l[100005],r[100005],ans=-1ll<<62;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>p>>q>>x;
	for (i=1;i<=n;i++) cin>>num[i];
	l[1]=p*num[1];r[n]=x*num[n];
	for (i=2;i<=n;i++) l[i]=max(l[i-1],p*num[i]);
	for (i=n-1;i;i--) r[i]=max(r[i+1],x*num[i]);
	for (i=1;i<=n;i++) ans=max(ans,l[i]+r[i]+q*num[i]);
	cout<<ans;
	return 0;
}