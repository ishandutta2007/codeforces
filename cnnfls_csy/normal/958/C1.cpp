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
long long n,m,p,i,j,num[100005],pre[100005],suf[100005],ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>p;
	for (i=1;i<=n;i++) cin>>num[i];
	for (i=1;i<=n;i++) pre[i]=(pre[i-1]+num[i])%p;
	for (i=n;i;i--) suf[i]=(suf[i+1]+num[i])%p;
	for (i=1;i<n;i++) ans=max(ans,pre[i]+suf[i+1]);
	cout<<ans;
	return 0;
}