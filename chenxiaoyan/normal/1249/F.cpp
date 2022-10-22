/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200;
int n,m;
int a[N+1];
vector<int> nei[N+1];
int f[N+1][N+2];
void dp(int x=1,int fa=0){
	vector<int> sum(max(n,m+1)+1),mx_Delta[max(n,m+1)+1];
	for(int i=0;i<=max(n,m+1);i++)mx_Delta[i].resize(max(n,m+1)+1);
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dp(y,x);
		for(int j=0;j<=max(n,m+1);j++)sum[j]+=f[y][j];
		for(int j=0;j<=max(n,m+1);j++)for(int k=0;k<=max(n,m+1);k++)mx_Delta[j][k]=max(mx_Delta[j][k],-f[y][j]+f[y][k]);
	}
	for(int i=0;i<=max(n,m+1);i++)
		for(int j=m/2+1;j<=max(n,m+1);j++)
			f[x][i]=max(f[x][i],sum[max(0,max(i,j)-1)]+mx_Delta[max(0,max(i,j)-1)][max(0,max(i,m-j+1)-1)]);
	f[x][0]=max(f[x][0],a[x]+f[x][m+1]);
//	for(int i=0;i<=max(n,m+1);i++)printf("f[%d][%d]=%d\n",x,i,f[x][i]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	dp();
	cout<<f[1][0];
	return 0;
}
/*1
5 1
1 2 3 4 5
1 2
2 3
3 4
3 5
*/
/*2
7 2
2 1 2 1 2 1 1
6 4
1 5
3 1
2 3
7 5
7 4
*/