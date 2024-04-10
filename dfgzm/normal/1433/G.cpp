#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pr printf
#define P push
#define PB push_back
#define F front
#define T top
#define MP make_pair
#define Fi first
#define Se second
#define inf 2147483647
using namespace std;
inline long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
inline long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
inline void read(long long &x){
	char ch;
	do ch=getchar();while(ch<48||ch>57);
	x=0;while(ch<=57&&ch>=48){x=x*10+ch-48;ch=getchar();}
}
inline void read(int &x){
	char ch;
	do ch=getchar();while(ch<48||ch>57);
	x=0;while(ch<=57&&ch>=48){x=x*10+ch-48;ch=getchar();}
}
int i,j,k,n,m,s;
struct edge{
	int next,to,w;
}a[2010];
int head[1010],len;
inline void add(int x,int y,int z){
	a[++len]=(edge){head[x],y,z};
	head[x]=len;
}
int vis[1010],dis[1010][1010];
queue<int>Q;
void dij(int S){
	int num=0;
	for(int i=1;i<=n;i++)dis[S][i]=inf,vis[i]=0;
	dis[S][S]=0;vis[S]=1;
	Q.P(S);
	while(!Q.empty()){
		int now=Q.F();
		vis[now]=0;
		Q.pop();
		for(int i=head[now];i;i=a[i].next){
			int u=a[i].to;
			if(a[i].w+dis[S][now]<dis[S][u]){
				dis[S][u]=a[i].w+dis[S][now];
				if(!vis[u])Q.P(u);
			}
		}
	}
}
struct ride{
	int x,y;
}R[1010];
int sum[2010];
vector<int>V[2010];
int ans=0;
signed main(){
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		int x,y,z;
		read(x);read(y);read(z);
		add(x,y,z);add(y,x,z);
	}
	for(i=1;i<=n;i++)dij(i);
	for(i=1;i<=k;i++){
		int x,y;
		read(x);read(y);
		R[i]={x,y};
		ans+=dis[x][y];
		for(j=1;j<=n;j++)
			for(int h=head[j];h;h=a[h].next){
				int u=a[h].to;
				sum[h]+=max(0,dis[x][y]-dis[x][j]-dis[u][y]);
			}
	}
	int Max1=0,Max2=0;
	for(i=1;i<=len;i+=2)
		if(sum[i]+sum[i+1]>Max1){
			Max1=sum[i]+sum[i+1];
			Max2=i;
		}
	cout<<ans-Max1<<endl;
	return 0;
}