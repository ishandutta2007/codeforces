#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#define maxn 300005
using namespace std;

int T,n,i,j,k;
struct Tree{
	int fa[maxn];
	int em,e[maxn],nx[maxn],ls[maxn];
	void clear(){em=0;memset(ls,0,sizeof(int)*(n+1));}
	void insert(int x,int y){
		em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	}
	int dfn[maxn],sz[maxn],tot,Idfn[maxn];
	void dfs(int x){
		dfn[x]=++tot,sz[x]=1,Idfn[tot]=x;
		for(int i=ls[x];i;i=nx[i]) 
			dfs(e[i]),sz[x]+=sz[e[i]];
	}
	void read(){
		clear(),tot=0;
		for(i=2;i<=n;i++) scanf("%d",&fa[i]),insert(fa[i],i);
		dfs(1);
	}
} t1,t2;

int check(int x,int y){	
	return x<=y&&y<=x+t2.sz[t2.Idfn[x]]-1;
}
set<int> S;
set<int>::iterator it;
int cnt,ans;
void dfs(int x){
	int u=t2.dfn[x];
	it=S.lower_bound(u);
	int tp=0,pre=0;
	if (it==S.end()||!check(u,*it)){
		cnt++,tp=1;
		if (it!=S.begin()){
			it--;
			if (check(*it,u)) pre=*it,cnt--,S.erase(it);
		}
		S.insert(u);
	} 
	ans=max(ans,cnt);
	for(int i=t1.ls[x];i;i=t1.nx[i]) dfs(t1.e[i]);
	if (tp) S.erase(u),cnt--;
	if (pre) S.insert(pre),cnt++;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		t1.read(),t2.read();
		ans=0,dfs(1);
		printf("%d\n",ans);
	}
}