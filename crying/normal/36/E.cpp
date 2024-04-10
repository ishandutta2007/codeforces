#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
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
const int MAXN=1e4+10,MAXM=2e4+10;
int n,m,u,v,sccnt;
struct Edge{
	int u,v,w,tag;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int fa[MAXN],size[MAXN],num[MAXN];
int st[MAXM],top;
vector<int>ans;
void addedge(int u,int v,int w){
	edge[++tot]=(Edge){u,v,w,0};
	next[tot]=first[u];first[u]=tot;
} 
int Find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=Find(fa[x]);
} 
void Merge(int x,int y){
	fa[Find(x)]=Find(y);
}
int alone(int x){
	return !size[x];
}
void Eular(int u){
	for(int j=first[u];j;j=next[j]){
		first[u]=next[j];
		if(edge[j].tag)continue;
		int v=edge[j].v;
		edge[j].tag=edge[op(j)].tag=1;
		Eular(v);
		st[++top]=edge[j].w;
	}
}
int Valid(int u){
	//u
	int cnt=0;
	rep(i,1,n){
		if(Find(i)!=Find(u))continue;
		cnt+=odd(size[i]);
	} 
	return Max(1,cnt/2);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=1e4;rep(i,1,n){
		fa[i]=i;
	}
	cin>>m;
	rep(i,1,m){
		cin>>u>>v;
		addedge(u,v,i),addedge(v,u,i);
		size[u]++;size[v]++;
		Merge(u,v);
	}
	rep(i,1,n){
		if(alone(i))continue;
		num[Find(i)]+=size[i]; 
		if(i==Find(i))sccnt++;
	}
	rep(i,1,n)num[i]/=2;
	if(sccnt>2){return printf("-1"),0;}
	if(sccnt==2){
		// 
		rep(i,1,n){
			if(alone(i))continue;
			if(Find(i)==i){
				if(Valid(i)>1){
					return printf("-1"),0;
				}
			}
		}
		rep(i,1,n){
			if(alone(i))continue;
			if(Find(i)==i){
				int root=i;
				rep(j,1,n){if(alone(j))continue;
					if(Find(i)!=Find(j))continue;
					if(odd(size[j]))root=j;
				}
				top=0;Eular(root);
				printf("%d\n",top);
				while(top)printf("%d ",st[top--]);
				printf("\n");
			}
		}
	}else{
		rep(i,1,n){
			if(alone(i))continue;
			if(Find(i)==i){
				int cs;
				if((cs=Valid(i))>2)return printf("-1"),0;
				if(num[i]==1)return printf("-1"),0;
				if(cs==1){
					// 
					int root=i;rep(j,1,n){if(alone(j))continue;
						if(odd(size[j]))root=j;
					}
					Eular(root);
					printf("1\n%d\n",st[top--]);
					printf("%d\n",top);
					while(top)printf("%d ",st[top--]);
				}else{
					//
					int u=0,v=0;
					rep(j,1,n){
						if(alone(j))continue;
						if(odd(size[j])){
							if(!u)u=j;
							else if(!v)v=j;
						}
					}
					addedge(u,v,m+1),addedge(v,u,m+1);size[u]++;size[v]++;
					rep(root,1,n){
						if(alone(root))continue;
						if(odd(size[root])){
							Eular(root);
							while(top && st[top]!=m+1)ans.pb(st[top--]);
							printf("%d\n",ans.size());
							for(vit it=ans.begin();it!=ans.end();it++)printf("%d ",*it);
							printf("\n");
							top--;printf("%d\n",top);
							while(top)printf("%d ",st[top--]);
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}