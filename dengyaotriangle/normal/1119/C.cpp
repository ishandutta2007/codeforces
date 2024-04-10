#include<bits/stdc++.h>

using namespace std;

const int maxn=505;

int n,m;

int a[maxn][maxn],b[maxn][maxn];
int cnh[2][maxn];
int cnr[2][maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cin>>b[i][j];
	
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cnh[0][i]+=a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cnh[1][i]+=b[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cnr[0][j]+=a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cnr[1][j]+=b[i][j];
	for(int i=1;i<=n;i++){
		if(cnh[0][i]%2!=cnh[1][i]%2){
			cout<<"No";
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if(cnr[0][i]%2!=cnr[1][i]%2){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}