#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int n,m,k;
int a[N][N],b[N],c[N];
int ans[N][N];
int main()
{
	cin>>n>>m>>k;
	int i,j;
	for(i=1;i<=m;i++) cin>>b[i];
	for(j=1;j<=n;j++) cin>>c[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) cin>>a[i][j];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			if(a[i][j]) ans[i][j]=inf;
	}
	for(i=1;i<=n;i++){
		int tmp=c[i];
		for(j=1;j<=m;j++) ans[i][j]=min(ans[i][j],tmp);
	}
	for(i=1;i<=m;i++){
		int tmp=b[i];
		for(j=1;j<=n;j++) ans[j][i]=min(ans[j][i],tmp);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}