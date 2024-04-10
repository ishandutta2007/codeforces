#include<bits/stdc++.h>
const int N=20;
using namespace std;

int f[N][1<<N],X[N][1<<N],I[N][1<<N],n,k,a[1<<N];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	memset(X,-2,sizeof(X));
	memset(f,1,sizeof(f));
	memset(I,1,sizeof(I));
	for(int i=1;i<=n;i++)cin>>a[i],X[0][a[i]]=I[0][a[i]]=0;
	for(int i=1;i<=k;i++)
		for(int j=0,p=1<<i-1;j<1<<k;j++)
			if(j>>(i-1)&1){
				int x=j,y=j^p;
				f[i][x]=f[i][y]=min(f[i-1][x],f[i-1][y]);
				f[i][x]=min(f[i][x],I[i-1][y]-X[i-1][x]+p);
				f[i][y]=min(f[i][y],I[i-1][x]-X[i-1][y]+p);
				X[i][x]=max(X[i-1][x],X[i-1][y]+p);
				I[i][x]=min(I[i-1][x],I[i-1][y]+p);
				X[i][y]=max(X[i-1][y],X[i-1][x]+p);
				I[i][y]=min(I[i-1][y],I[i-1][x]+p);
			}
	for(int i=0;i<1<<k;i++)
		cout<<f[k][i]<<' ';
}