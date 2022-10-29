#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5005
#define maxm 20005
#define maxe 100005
#define inf 2e9
#define ll long long 
using namespace std;

int n,i,j,k,tim,p[maxn];
ll A[maxn],B[maxn],C[maxn],D[maxn];
int cmp1(int i,int j){return B[i]<B[j]||B[i]==B[j]&&C[i]>C[j];}
int cmp2(int i,int j){return D[i]>D[j]||D[i]==D[j]&&i<j;}
int cmp3(int i,int j){return B[i]<B[j];}
int cmp4(int i,int j){return C[i]<C[j];}

int check(ll t){
	for(i=1;i<=2*n;i++) C[i]=A[i]*t+B[i];
	for(i=1;i<=2*n;i++) p[i]=i;
	sort(p+1,p+1+2*n,cmp1);
	for(i=2;i<=2*n;i++) C[p[i]]=max(C[p[i]],C[p[i-1]]);
	for(i=1;i<=n;i++) D[i]=C[i];
	for(i=n+1;i<=2*n;i++) D[i]=A[i]*t+B[i];
	for(i=1;i<=2*n;i++) p[i]=i;
	sort(p+1,p+1+2*n,cmp2);
	int cnt=0;
	for(i=1;i<=2*n;i++) if (p[i]<=n) cnt++;
	else {if (!cnt) return 0;cnt--;}
	return 1;
}

void mergetime(){
	ll l=0,r=1e9,mid; tim=-1;
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid)) tim=mid,r=mid-1;
		else l=mid+1;
	}
}

int em,e[maxe],nx[maxe],ls[maxm],ec[maxe],cost[maxe];
int L[maxn],R[maxn],S,T,tot,now,pre;

void insert(int x,int y,int z,int c){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; ec[em]=z; cost[em]=c;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em; ec[em]=0; cost[em]=-c;
}

const int maxd=100005;
int t,w,d[maxd],dis[maxm],vis[maxm],ans;
int SPFA(){
	for(i=1;i<=tot;i++) vis[i]=0,dis[i]=inf;
	t=0,w=1,d[w]=T,vis[T]=1,dis[T]=0;
	while (t<w){
		t=(t+1)%maxd; int x=d[t]; vis[x]=0;
		for(i=ls[x];i;i=nx[i]) 
		if (ec[i^1]&&dis[x]-cost[i]<dis[e[i]]){
			dis[e[i]]=dis[x]-cost[i];
			if (!vis[e[i]]) {
				vis[e[i]]=1,w=(w+1)%maxd,d[w]=e[i];
				k=(t+1)%maxd;
				if (dis[e[i]]<dis[d[k]]) swap(d[w],d[k]);
			}
		}
	}
	return dis[S]<inf;
}

int dfs(int x,int p){
	if (x==T) {return p;}
	int res=p; vis[x]=1;
	for(int i=ls[x];i&&res;i=nx[i]) 
	if (ec[i]&&!vis[e[i]]&&dis[x]-cost[i]==dis[e[i]]){
		int tmp=dfs(e[i],min(res,ec[i]));
		ans+=cost[i]*tmp,ec[i]-=tmp,ec[i^1]+=tmp;
		res-=tmp;
	}
	return p-res;
}

void maxflow(){
	int sum=0;
	while (SPFA()){
		memset(vis,0,sizeof(vis));
		sum+=dfs(S,inf);
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n*2;i++) scanf("%lld%lld",&A[i],&B[i]);
	mergetime();
	if (tim==-1) {printf("-1");return 0;}
	for(i=1;i<=2*n;i++) L[i]=i,R[i]=i+2*n; tot=4*n,em=1;
	for(i=1;i<=2*n;i++) insert(L[i],R[i],inf,0);
	
	for(i=1;i<=2*n;i++) p[i]=i; sort(p+1,p+1+2*n,cmp3);
	for(pre=0,i=1;i<=2*n;i=j){
		for(j=i;j<=2*n&&B[p[j]]==B[p[i]];j++);
		now=++tot; if (pre) insert(now,pre,inf,0);
		for(k=i;k<j;k++) insert(L[p[k]],now,inf,1),insert(now,L[p[k]],inf,0);
		pre=now;
	}
	for(i=1;i<=2*n;i++) C[i]=A[i]*tim+B[i],p[i]=i; sort(p+1,p+1+2*n,cmp4);
	for(pre=0,i=1;i<=2*n;i=j){
		for(j=i;j<=2*n&&C[p[j]]==C[p[i]];j++);
		now=++tot; 
		if (pre) insert(now,pre,inf,0);
		for(k=i;k<j;k++) insert(R[p[k]],now,inf,1),insert(now,R[p[k]],inf,0);
		pre=now;
	}
	S=++tot,T=++tot;
	for(i=1;i<=n;i++) insert(S,L[i],1,0),insert(R[n+i],T,1,0);
	maxflow();
	printf("%d %d",tim,ans);
}