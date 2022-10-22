#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
vector<int> ga[N],gb[N];
int n,a,b;
int ca[N],cb[N];
int dp[N][N][2];//0 a 1 b
int ha[N],hb[N];
int lfta[N],rgta[N],lftb[N],rgtb[N];
int cnta,cntb;
int faa[N][11],fab[N][11];
void dfsa(int u,int last){
	lfta[u]=++cnta;
	ha[u]=ha[last]+1;
	for(int i=1;i<11;i++)
		faa[u][i]=faa[faa[u][i-1]][i-1];
	for(auto v:ga[u]){
		if(v==last) continue;
		faa[v][0]=u;
		dfsa(v,u);
	}
	rgta[u]=cnta;
}
void dfsb(int u,int last){
	lftb[u]=++cntb;
	hb[u]=hb[last]+1;
	for(int i=1;i<11;i++)
		fab[u][i]=fab[fab[u][i-1]][i-1];
	for(auto v:gb[u]){
		if(v==last) continue;
		fab[v][0]=u;
		dfsb(v,u);
	}
	rgtb[u]=cntb;
}
int costa(int u,int v){
	int x=u;
	if(!v) return ha[u]-1;
	for(int i=10;i>=0;i--){
		if(!faa[x][i]) continue;
		if(lfta[faa[x][i]]<=lfta[v]&&rgta[faa[x][i]]>=rgta[v]) continue;
		x=faa[x][i];
	}
	return ha[u]-ha[x]+1;
}
int costb(int u,int v){
	int x=u;
	if(!v) return hb[u]-1;
	for(int i=10;i>=0;i--){
		if(!fab[x][i]) continue;
		if(lftb[fab[x][i]]<=lftb[v]&&rgtb[fab[x][i]]>=rgtb[v]) continue;
		x=fab[x][i];
	}
	return hb[u]-hb[x]+1;
}
int main(){
	int i,j;
	cin>>n;
	cin>>a;
	for(i=2;i<=a;i++){
		int fa;cin>>fa;
		ga[i].push_back(fa);
		ga[fa].push_back(i); 
	}
	for(i=1;i<=n;i++) cin>>ca[i];
	cin>>b;
	for(i=2;i<=b;i++){
		int fa;cin>>fa;
		gb[i].push_back(fa);
		gb[fa].push_back(i);
	}
	for(i=1;i<=n;i++) cin>>cb[i];
	dfsa(1,0);
	dfsb(1,0);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=dp[0][0][1]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<i;j++){
			dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+costa(ca[i],ca[i-1]));
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]+costb(cb[i],cb[i-1]));
			dp[i][i-1][0]=min(dp[i][i-1][0],dp[i-1][j][1]+costa(ca[i],ca[j]));
			dp[i][i-1][1]=min(dp[i][i-1][1],dp[i-1][j][0]+costb(cb[i],cb[j]));
		}
	}
	int ans=0x3f3f3f3f;
	for(i=0;i<n;i++){
		ans=min(ans,dp[n][i][0]);
		ans=min(ans,dp[n][i][1]);
	}
	cout<<(a-1)+(b-1)-ans;
	return 0;
}