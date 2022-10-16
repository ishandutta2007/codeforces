#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int r,n,t[100005],x[100005],y[100005];
int f[100005],ans;
int main(){
	cin>>r>>n;
	for (int i=1;i<=n;i++)scanf("%d%d%d",&t[i],&x[i],&y[i]);
	for (int i=1;i<=n;i++){
		f[i]=-114514;
		if (x[i]-1+y[i]-1<=t[i])f[i]=1;
		for (int j=i-1;j>=i-4*r&&j>=1;j--)
			if (abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}