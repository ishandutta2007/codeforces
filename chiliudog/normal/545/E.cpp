#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=3e5+5,maxm=6e5+5;
long long inf=1ll<<60;
int head[maxn],t[maxm],ne[maxm],pre[maxn],num,u,posi[maxn],tot;
bool inq[maxn];
long long d[maxn],v[maxm];
int Queue[9000000+5],n,m;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

inline void dijkstra_with_heap(){
	int front=0,finish=1;d[u]=0;inq[u]=true;Queue[1]=u;
	while(front!=finish){
		int x=Queue[++front];
		if (front>=9e6+5) front-=9e6+5;
		for(int i=head[x];i!=-1;i=ne[i])
			if (d[t[i]]>d[x]+v[i]){
				pre[t[i]]=i;
				d[t[i]]=d[x]+v[i];
				if (!inq[t[i]]){
					Queue[++finish]=t[i];
					inq[t[i]]=true;
					if (finish>=9e6+5) finish-=9e6+5;
				}
			}
			else if (d[t[i]]==d[x]+v[i]){
				if (v[pre[t[i]]]>v[i]) pre[t[i]]=i;
			}
		inq[x]=false;
	}
}
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];
	head[x]=num;
	t[num]=y;
	v[num]=z;
	ne[++num]=head[y];
	head[y]=num;
	t[num]=x;
	v[num]=z;
}
int main(){
//	judge();
	read(n);read(m);
	fortodo(i,1,n) head[i]=-1;
	fortodo(i,1,m){
		int x,y,z;
		read(x);read(y);read(z);
		addedge(x,y,z);
	}read(u);
	fortodo(i,1,n) d[i]=inf;
	long long ans=0;
	dijkstra_with_heap();
	fortodo(i,1,n) if (i!=u) ans+=v[pre[i]];
	cout<<ans<<endl;
	fortodo(i,1,n) if (i!=u) posi[++tot]=(pre[i]+1)/2;
	sort(posi+1,posi+n);
	fortodo(i,1,n-1) printf("%d ",posi[i]);
    return 0;
}