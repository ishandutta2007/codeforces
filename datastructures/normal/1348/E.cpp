#include <iostream>
#include <cstdio>
#define int long long
using namespace std; 
int n,c,sum,a[1005],b[1005],f[1005][1005],ans;
signed main(){
	cin>>n>>c;
	for (int i=1;i<=n;i++)cin>>a[i]>>b[i],sum+=a[i]+b[i];
	f[0][0]=1;
	for (register int i=1;i<=n;i++)
		for (register int j=0;j<c;j++)
			for (register int k=0;k<c&&k<=a[i];k++){
				if (b[i]<(c-k)%c)continue;
				int last=j-(a[i]-k);
				last=(last%c+c)%c;
				if (f[i-1][last]==1){
					f[i][j]=1;
					break;
				}
			}
	ans=sum/c-1;
	for (int i=0;i<c;i++)
		if (f[n][i]==1&&i<=sum%c)ans=sum/c;
	cout<<ans<<endl; 
	return 0;
}