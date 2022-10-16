#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10,MAXM=2e5+10;
struct Edge{
	int u,v;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int n,c[MAXN][4],u,v,size[MAXN],head;
int pre[MAXN],nxt[MAXN],color[MAXN];
ll sum,ans=1e18,sol[MAXN];
void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;
	next[tot]=first[u];first[u]=tot;
}
int main(){
	cin>>n;
	rep(i,1,3){
		rep(j,1,n)cin>>c[j][i];
	}
	rep(i,1,n-1){
		cin>>u>>v;
		addedge(u,v),addedge(v,u);
		size[u]++;size[v]++;
		if(size[u]>=3 || size[v]>=3){
			printf("-1\n");return 0;
		}
	}
	//
	rep(i,1,n)if(size[i]==1)head=i; 
	int now=head;
	rep(i,1,n){
		for(int j=first[now];j;j=next[j]){
			int v=edge[j].v;
			if(v==pre[now])continue;
			nxt[now]=v;
			pre[v]=now;
		}
		now=nxt[now];
	}
	//headnxt[head]
	rep(c1,1,3){
		rep(c2,1,3){
			if(c1==c2)continue;
			int c3=1;
			if(c1==1 || c2==1){
				c3++;
				if(c1==2 || c2==2){
					c3++;
				}
			}
			now=head;sum=0;
			int cnt=1;
			while(now){
				if(cnt%3==1)color[now]=c1;
				else if(cnt%3==2)color[now]=c2;
				else color[now]=c3;
				sum+=c[now][color[now]];
				now=nxt[now];
				cnt++;
			}
			if(sum<ans){
				rep(i,1,n)sol[i]=color[i];
				ans=sum;
			}
		}
	} 
	printf("%lld\n",ans);
	rep(i,1,n){
		printf("%d ",sol[i]);
	}
	return 0;
}