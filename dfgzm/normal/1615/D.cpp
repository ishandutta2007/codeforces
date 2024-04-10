#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=800010;
struct edge{
	int next,to,w,S;
}a[maxn*2];
int head[maxn],len;
void add(int x,int y,int z,int S){
	a[++len]={head[x],y,z,S};
	head[x]=len;
}
int i,j,k,n,m,F[maxn];
int sum[maxn];
int find(int x){
	return F[x]==x?F[x]:F[x]=find(F[x]);
}
void dfs(int now,int fa){
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		if(a[i].w==0)F[find(now)]=find(u),F[find(now+n)]=find(u+n);
		if(a[i].w==1)F[find(now)]=find(u+n),F[find(now+n)]=find(u);
		dfs(u,now);
	}
}
void dfs2(int now,int fa){
//	cout<<' '<<now<<' '<<fa<<endl;
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		int ans=0;
		if(a[i].w==-1){
			if(find(now)==find(u+n) || find(now+n)==find(u))ans=1,F[find(now)]=find(u+n),F[find(now+n)]=find(u);
			else ans=0,F[find(now)]=find(u),F[find(now+n)]=find(u+n);
		}else ans=a[i].S;
		printf("%d %d %d\n",now,u,ans);
		dfs2(u,now);
	}
}
int ans[maxn];
int main() {
	int T=read();
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)head[i]=0;len=0;
		for(i=1;i<=2*n;i++)F[i]=i;
		for(i=1;i<n;i++){
			int x=read(),y=read(),z=read();
			int tmp=z;
			if(z!=-1){
				int num=0;
				while(z){
					num+=z%2;
					z/=2;
				}num%=2;z=num;
			}
			add(x,y,z,tmp);
			add(y,x,z,tmp);
		}
		dfs(1,0);
		for(i=1;i<=m;i++){
			int x,y,z;
			x=read();y=read();z=read();
			if(z==0)F[find(x)]=find(y),F[find(x+n)]=find(y+n);
			if(z==1)F[find(x)]=find(y+n),F[find(x+n)]=find(y);
		}
		bool b=0;
		for(i=1;i<=n;i++)if(find(i)==find(i+n))b=1;
		if(b)puts("NO");
		else{
			puts("YES");
			dfs2(1,0);
		}
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}