#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
char ch[505][505];
int a[505][505];
int c[505],d[505],e;
int val,ans;
int s,t,totm=1,u[1000005],v[1000005],w[1000005],first[1005],nxt[1000005];
int head,tail,q[1005],depth[1005],cur[1005];
void add(int a,int b,int c){
	int i=++totm;
	u[i]=a,v[i]=b,w[i]=c;
	nxt[i]=first[u[i]],first[u[i]]=i;
	i=++totm;
	u[i]=b,v[i]=a,w[i]=0;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
bool bfs(){
	for (int i=1;i<=t;i++)depth[i]=-1,cur[i]=first[i];
	head=tail=1,q[1]=s;
	depth[s]=0;
	while(head<=tail){
		int now=q[head];
		if (now==t)return 1;
		head++;
		for (int i=first[now];i;i=nxt[i]){
			if (depth[v[i]]==-1&&w[i]>0){
				depth[v[i]]=depth[now]+1;
				q[++tail]=v[i];
			}
		}
	}
	return 0;
}
int dfs(int now,int in){
	if (now==t)return in;
	int out=0;
	for (int i=first[now];i!=0&&in>0;i=nxt[i])
		if (depth[v[i]]==depth[now]+1&&w[i]>0){
			int qwq=dfs(v[i],min(in,w[i]));
			w[i]-=qwq,w[i^1]+=qwq;
			in-=qwq,out+=qwq;
		}
	return out;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for (int j=1;j<=m;j++){
			if (ch[i][j]=='W')a[i][j]=0;
			if (ch[i][j]=='B')a[i][j]=1;
		}
	}
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
			a[i][j]=(a[i][j]^a[i][j-1]^a[i-1][j]^a[i-1][j-1]);
	e=a[1][1];
	for (int i=2;i<=n;i++)c[i]=a[i][1];
	for (int i=2;i<=m;i++)d[i]=a[1][i];
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (a[i][j]==1)c[i]^=1,d[j]^=1,e^=1,val++;
	for (int i=2;i<=n;i++)
		if (c[i]==1)val++,e^=1;
	for (int i=2;i<=m;i++)
		if (d[i]==1)val++,e^=1;
	s=n+m+1,t=n+m+2;
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (c[i]+d[j]==2&&a[i][j]==1)add(i,j+n,1);
	for (int i=1;i<=n;i++)add(s,i,1);
	for (int i=1;i<=m;i++)add(i+n,t,1);
	int f=0;
	while(bfs())f+=dfs(s,n);
	ans=val-f;
	if ((e+f)%2==1)ans++;
	cout<<ans<<endl;
	return 0;
}
//qwq