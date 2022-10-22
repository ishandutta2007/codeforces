#pragma optimize("Ofase")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000;
struct Graph{
	struct Edge{ int to,nxt,c,key; }edge[40005];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	void init(int n){memset(head,-1,sizeof(int)*(n+1)),top=-1;}
	inline void add(int x,int y,int c,int key){
		edge[++top]=(Edge){y,head[x],c,key};
		head[x]=top;
	}
}G;
void add2(int x,int y,int c,int key){
//	printf("[%d %d %d %d]",x,y,c,key);
	G.add(x,y,c,key);
	G.add(y,x,0,-key);
}
struct K{
	 int a,b,id;
	 inline ll query(int x){ return 1ll*a*x+b; }
};
int ti;
inline bool cmp(K x,K y){ 
	ll kx=x.query(ti),ky=y.query(ti);
	if(kx!=ky) return kx<ky;
	return x.id>y.id;
}
namespace FLOW{
	int iter[N],lev[N],q[N],left,right;
	bool vis[N];
	inline bool bfs(int s,int t,int n){
		for(int i=0;i<=n;++i) lev[i]=0,iter[i]=G.head[i],vis[i]=0;
		left=right=0;
		q[right++]=s; lev[s]=1;
		while(left!=right){
			int x=q[left++];
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[right++]=y;
				}
			}
		}
		return lev[t]>0;
	}
	int dfs(int x,int o,int mi){
		if(x==o) return mi;
		vis[x]=1; int sum=0;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]==lev[x]+1&&!vis[y]){
				int d=dfs(y,o,min(mi,G.edge[j].c));
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					sum+=d;
					if(sum==mi) break;
				}
			}
		}
		vis[x]=0; return sum;
		return 0;
	}
	int max_flow(int s,int t,int n){
		int ret=0,d;
		while(bfs(s,t,n)){
			while((d=dfs(s,t,(int)1e9))!=0)
				ret+=d;
		}
		return ret;
	}
	inline pair<int,int> spfa(int s,int t,int n){
		int *dis=iter,*pre=lev;
		for(int i=0;i<=n;++i) vis[i]=0,dis[i]=(int)1e9,pre[i]=-1;
		left=right=0; q[right++]=s; dis[s]=0; vis[s]=1;
		while(left!=right){
			int x=q[left++]; vis[x]=0; if(left>n+2) left=0;
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&dis[x]+G.edge[j].key<dis[y]){
					dis[y]=dis[x]+G.edge[j].key;
					pre[y]=j;
					if(!vis[y]){
						q[right++]=y; if(right>n+2) right=0;
						vis[y]=1;
					}
				}
			}
		}
		if(pre[t]==-1) return make_pair(-1,-1);
		pair<int,int> ret(dis[t],(int)1e9);
		for(int j=pre[t];~j;j=pre[G.edge[j^1].to])
			ret.second=min(ret.second,G.edge[j].c);
		for(int j=pre[t];~j;j=pre[G.edge[j^1].to]){
			G.edge[j].c-=ret.second;
			G.edge[j^1].c+=ret.second;
		}
		return ret;
	}
	pair<int,int> cost_flow(int s,int t,int n){
		pair<int,int> ret(0,0),d;
		while((d=spfa(s,t,n)).second!=-1){
			ret.first+=d.first*d.second;
			ret.second+=d.second;
		}
		return ret;
	}
}
int n;
K a[N],b[N];
int rka[N],rkb[N],ida[N],idb[N],mx[N];
bool check(int time){
	ti=time;
	for(int i=1;i<=n+n;++i) b[i]=a[i];
	sort(b+1,b+n+n+1,cmp);
	int cb=0,last=0;
	for(int i=1;i<=n+n;++i){
		if(b[i].id>n) ++cb;
		idb[b[i].id]=cb;
	}
	mx[0]=0;
	for(int i=1;i<=n+n;++i)
		mx[i]=max(mx[i-1],idb[a[i].id]);
	for(int i=1;i<=n+n;++i){
		if(a[i].id<=n){
			ti=0;
			int pos=upper_bound(a+1,a+n+n+1,a[i],cmp)-a-1;
			if(last<mx[pos]) ++last;
			else return false;
		}
	}
	return true;
}
pair<int,int> solve(int time){
	ti=time; 
	for(int i=1;i<=n+n;++i) b[i]=a[i];
	sort(b+1,b+n+n+1,cmp);
	G.init(n*4+2);
	int top_node=n+n,s=++top_node,t=++top_node,ca=0,cb=0;	
	for(int i=1;i<=n;++i){
		add2(s,i,1,0);
		add2(i+n,t,1,0);
		ida[i]=++top_node,idb[i]=++top_node;
		if(i>1){
			add2(ida[i],ida[i-1],(int)1e9,0);
			add2(idb[i],idb[i-1],(int)1e9,0);
		}
	}
	for(int i=1;i<=n+n;++i){
		if(a[i].id>n){
			++ca;
			add2(ida[ca],a[i].id,1,0);
		}
		if(b[i].id>n){
			++cb;
			add2(idb[cb],b[i].id,1,0);
		}
		rka[a[i].id]=ca;
		rkb[b[i].id]=cb;
	}
	mx[0]=0;
	for(int i=1;i<=n+n;++i)
		mx[i]=max(mx[i-1],rkb[a[i].id]);
	for(int i=1;i<=n+n;++i)
		if(a[i].id<=n){
			ti=0;
			int pos=upper_bound(a+1,a+n+n+1,a[i],cmp)-a-1;
			if(pos>0){
				if(rka[a[pos].id]>0)
					add2(a[i].id,ida[rka[a[pos].id]],1,1);
				if(rkb[a[i].id]>0)
					add2(a[i].id,idb[rkb[a[i].id]],1,1);
				if(mx[pos]>0)
					add2(a[i].id,idb[mx[pos]],1,2);
			}
		}
	return FLOW::cost_flow(s,t,top_node);
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&n);
	clock_t ss=clock();
	for(int i=1;i<=n+n;++i)
		scanf("%d%d",&a[i].a,&a[i].b),a[i].id=i;
	sort(a+1,a+n+n+1,cmp);
	int left=0,right=(int)1e9+1;
//	printf("<%d>",check(3));
	while(left<right){
		int mid=left+right>>1;
		if(check(mid)) right=mid;
		else left=mid+1;
	}
	if(right==(int)1e9+1){
		puts("-1");
		exit(0);
	}else{
		pair<int,int> ret=solve(right);
		printf("%d %d\n",right,ret.first);
	}
	return 0;
}