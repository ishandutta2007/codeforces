#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

int a[N],n,s[N],ans,f[N][N],g[N][N];

main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],a[i]=-a[i];
		if(i&1)a[i]=-a[i];
		s[i]=s[i-1]+a[i],f[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j]=min(s[j]-s[i-1],f[i][j-1]);
	for(int i=1;i<=n;i+=2)
		for(int j=i+1;j<=n;j+=2){
			int dl=s[j-1]-s[i],mn=f[i+1][j-1];
			int mnl=max(-mn,1ll)+dl,mnr=1ll,mxl=a[i]+dl,mxr=-a[j];
			ans+=max(0ll,min(mxl,mxr)-max(mnl,mnr)+1);
		}
	cout<<ans;
}