#include<bits/stdc++.h>
using namespace std;
int T;
int ds[404][404];
int a[404][404];
char c[404][404];
int t[404][2];
int d[404];
void sol(){
	int ans=1e9;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		ds[i][j]=ds[i][j-1]+(a[i][j]=(c[i][j]-'0'));
	for(int i=1;i<=m;i++)for(int j=i+3;j<=m;j++){
		int s=1e9;
		for(int k=1;k<=n;k++){
			int A=ds[k][j-1];
			t[k][1]=j-i-1-(ds[k][j-1])+(ds[k][i]);
			t[k][0]=(!a[k][i])+(!a[k][j])+(ds[k][j-1]-ds[k][i]);
			d[k]=d[k-1]+t[k][0];
		}
		for(int k=5;k<=n;k++){
			s=min(s+t[k-1][0],t[k-4][1]+d[k-1]-d[k-4]);
			ans=min(ans,s+t[k][1]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	cin>>T;
	while(T--)sol();
}