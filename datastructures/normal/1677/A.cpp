#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int t,n,p[5005],pre[5005][5005],suf[5005][5005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=0;i<=n+1;i++)
			for (int j=0;j<=n+1;j++)pre[i][j]=suf[i][j]=0;
		for (int i=1;i<=n;i++)cin>>p[i];
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)pre[i][j]=pre[i-1][j];
			for (int j=p[i];j<=n;j++)pre[i][j]++;
		}
		for (int i=n;i>=1;i--){
			for (int j=1;j<=n;j++)suf[i][j]=suf[i+1][j];
			for (int j=p[i];j<=n;j++)suf[i][j]++;
		}
		ll ans=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				ans+=1ll*pre[i-1][p[j]-1]*suf[j+1][p[i]-1];
		cout<<ans<<endl;
	}
	return 0;
}