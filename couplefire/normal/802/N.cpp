#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 2300
#define M 10000
using namespace std;

struct Edge{
	int to,next,from;
	ll v,c;
}e[M<<1];

int ne=1,head[N],from[N];
bool inq[N];
int a[N],b[N],n,k;
int S,T,SS;
ll dis[N],ans;
queue<int> q;

void ins(int u,int v,ll f,int c){
	ne++;
	e[ne].to=v;
	e[ne].from=u;
	e[ne].v=f;
	e[ne].c=c;
	e[ne].next=head[u];
	head[u]=ne;
}

void insert(int u,int v,ll f,int c){
	ins(u,v,f,c);ins(v,u,0,-c);
}

bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	q.push(S);
	while(!q.empty()){
		int now=q.front();q.pop();
		inq[now]=0;
		for(int i=head[now];i;i=e[i].next){
			int v=e[i].to;
			if(e[i].v==0) continue;
			if(dis[v]>dis[now]+e[i].c){
				dis[v]=dis[now]+e[i].c;
				from[v]=i;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	if(dis[T]!=inf) return 1;
	return 0;
}

void mcmf(){
	ll mn=inf;
	for(int i=T;i;i=e[from[i]].from){
		mn=min(e[from[i]].v,mn);
	}
	for(int i=T;i;i=e[from[i]].from){
		e[from[i]].v-=mn;
		e[from[i]^1].v+=mn;
		ans+=e[from[i]].c*mn;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	S=0;SS=n+1;T=n+2;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	insert(S,SS,k,0);
	for(int i=1;i<=n;i++){
		insert(SS,i,1,a[i]);
		insert(i,T,1,b[i]);
		if(i!=n) insert(i,i+1,inf,0);
	}
	while(spfa()) mcmf();
	cout<<ans<<endl;
	return 0;
}