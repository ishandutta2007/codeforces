#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int r[1005],c[1005],a[1005][1005],s[1005][1005];
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>r[0]>>c[0];
	for (int i=1;i<=r[0];i++){
		int x;
		scanf("%I64d",&x);
		r[i]=x;
		for (int j=1;j<=x;j++)a[i][j]=1;
	} 
	for (int i=1;i<=c[0];i++){
		int x;
		scanf("%I64d",&x);
		c[i]=x;
		for (int j=1;j<=x;j++)a[j][i]=1;
	}
	int flag=1;
	for (int i=1;i<=r[0];i++)
		if (a[i][r[i]+1]==1)flag=0;
	for (int i=1;i<=c[0];i++)
		if (a[c[i]+1][i]==1)flag=0;
	int ans=1;
	for (int i=1;i<=r[0];i++){
		for (int j=r[i]+2;j<=c[0];j++)
			if (a[i][j]!=1)s[i][j]++;
	}
	for (int j=1;j<=c[0];j++){
		for (int i=c[j]+2;i<=r[0];i++)
			if (a[i][j]!=1)s[i][j]++;
	}	
	for (int i=1;i<=r[0];i++)
		for (int j=1;j<=c[0];j++)
			if (s[i][j]==2)ans=ans*2%mod;
	if (flag==1)cout<<ans<<endl;
	else cout<<0<<endl;
}