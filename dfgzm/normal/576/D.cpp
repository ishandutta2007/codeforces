#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=155;
struct edge{
	int x,y,z;
}e[maxn*2];
int i,j,k,n,m,T;
bitset<maxn>vis[maxn],d,tmp,tr[maxn],tmpv[maxn];
bitset<maxn>I[maxn];
bool cmp(edge a,edge b){
	return a.z<b.z;
}
bitset<maxn> ans[maxn];
void mul(bitset<maxn> *a,bitset<maxn> *b){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=false;
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			if(a[i][k])
				ans[i]|=b[k];
	for(int i=1;i<=n;i++)a[i]=ans[i];
}
void ksm(int x){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			I[i][j]=(i==j),tmpv[i][j]=vis[i][j];
	while(x){
		if(x&1)mul(I,tmpv);
		mul(tmpv,tmpv);
		x>>=1;
	}
	//for(int i=1;i<=n;i++)vis[i]=I[i];
}
void POW(int x){
	ksm(x);
	for(int i=1;i<=n;i++)tmp[i]=false;
	for(int i=1;i<=n;i++)
		if(d[i])tmp|=I[i];
	d=tmp;
}
int dis[maxn];
int Q[maxn],l,r;
int dfs(int t){
	l=1;r=0;memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;i++)
		if(d[i])Q[++r]=i,dis[i]=t;
	while(l<=r){
		int now=Q[l++];
	//	cout<<"now="<<now<<endl;
		for(int i=1;i<=n;i++)
			if(tr[now][i] && dis[i]==-1)
				dis[i]=dis[now]+1,Q[++r]=i;
	}
	return dis[n]>=0?dis[n]:1111111111;
}
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		e[i]={x,y,z};
	}
	sort(e+1,e+1+m,cmp);
	d[1]=1;
	//for(i=1;i<=n;i++)vis[i][i]=1;
	int now=0,ans=2e9;
	for(i=1;i<=m;i++){
		POW(e[i].z-now);
		now=e[i].z;
	/*	
		cout<<"i="<<i<<" T="<<now<<endl;
		for(j=1;j<=n;j++)cout<<d[j]<<' ';cout<<endl;
	*/	
		vis[e[i].x][e[i].y]=true;
		tr[e[i].x][e[i].y]=true;
		ans=min(ans,dfs(now));
	}
	if(ans>1011111111)puts("Impossible");
	else cout<<ans<<endl;
}