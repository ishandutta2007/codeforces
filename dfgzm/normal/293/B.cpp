#include<bits/stdc++.h>
using namespace std;
const int maxn=11,mod=1e9+7,maxS=2049;
int i,j,k,n,m,a[maxn][maxn],f[maxn][maxn],num[maxS],vis[maxn],MAX;
int dfs(int x,int y){
	if(y==m+1){x++;y=1;}
	if(x==n+1){return 1;}
//	cout<<"dfs.. x="<<x<<" y="<<y<<" "<<MAX<<' '<<a[x][y]<<' '<<endl;
	f[x][y]=f[x-1][y]|f[x][y-1];
	if(a[x][y]){
		if(f[x][y]&(1<<a[x][y]-1))return 0;
		else{
			f[x][y]|=(1<<a[x][y]-1);
			return dfs(x,y+1);
		}
	}int use=MAX-f[x][y];
	if(num[use]<(n-x)+(m-y)+1)return 0;
	int ans=0,w=-1;
	for(int i=0;i<k;i++){
		if(f[x][y]&(1<<i))continue;
		f[x][y]^=(1<<i);
		vis[i+1]++;
		if(vis[i+1]==1){
			if(w<0)w=dfs(x,y+1);
			ans+=w;
		}else ans+=dfs(x,y+1);
		if(ans>=mod)ans-=mod;
		f[x][y]^=(1<<i);
		vis[i+1]--;
	}return ans;
}
int main(){
//	freopen("in","r",stdin);
	num[0]=0;for(i=1;i<maxS;i++)num[i]=num[i/2]+(i%2);
	cin>>n>>m>>k;
	MAX=(1<<k)-1;
	if(n+m-1>k){
		puts("0");
		return 0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			vis[a[i][j]]++;
		}
	cout<<dfs(1,1)<<endl;
	cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}