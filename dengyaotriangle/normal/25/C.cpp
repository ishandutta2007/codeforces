#include<bits/stdc++.h>

using namespace std;

const int maxn=305;

int d[maxn][maxn];
int n;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>d[i][j]; 
	} 
	int k;
	cin>>k;
	while(k--){
		int u,v,w;
		cin>>u>>v>>w;
		long long sm=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][u]+d[v][j]+w);
				d[i][j]=min(d[i][j],d[i][v]+d[u][j]+w);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)sm+=d[i][j];
		}
		cout<<sm<<' ';
	}
	return 0;
}