#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5;
int n,m,K;
int w[11][N][N];
int a[N][N],b[N][N];
int main(){
	int i,j,k;
	cin>>n>>m>>K;
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++) cin>>a[i][j];
	}
	for(i=1;i<n;i++){
		for(j=1;j<=m;j++) cin>>b[i][j];
	}
	if(K&1){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				cout<<-1<<" ";
			cout<<endl;
		}
		return 0;
	}
	K>>=1;
	for(k=1;k<=K;k++){
		memset(w[k],0x3f,sizeof(w[k]));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i<n) w[k][i][j]=min(w[k][i][j],w[k-1][i+1][j]+b[i][j]);
				if(j<m) w[k][i][j]=min(w[k][i][j],w[k-1][i][j+1]+a[i][j]);
				if(i>1) w[k][i][j]=min(w[k][i][j],w[k-1][i-1][j]+b[i-1][j]);
				if(j>1) w[k][i][j]=min(w[k][i][j],w[k-1][i][j-1]+a[i][j-1]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) cout<<w[K][i][j]*2<<" ";
		cout<<endl;
	}
	return 0;
}