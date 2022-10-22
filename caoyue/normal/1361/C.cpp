#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e6+7;
const int INF=1e9+7;
int n;
int A[N],B[N],f[N],sm[N],to[N],g[N],h[N];
set<int>S[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
bool check(int x){
	rep0(i,(1<<x))f[i]=i,sm[i]=0;
	rep(i,n){
		int u=ff(A[i]%(1<<x)),v=ff(B[i]%(1<<x));
		if(u!=v)f[u]=v;
		sm[A[i]%(1<<x)]++;
		sm[B[i]%(1<<x)]++;
	}
	int dd=-1;
	rep0(i,(1<<x)){
		if(!sm[i])continue;
		if(~dd)if(ff(i)!=dd)return 0;
		dd=ff(i);
	}
	rep0(i,(1<<x))if(sm[i]&1)return 0;
	return 1;
}
void solve(int x,int xx){
	if(h[x])return;
	int y=((x-1)^1)+1,d=(x+1)/2;
	h[x]=h[y]=1;
	g[ff(d)]=1;
	printf("%d %d ",x,y);
	int u=((y&1)?A[d]:B[d])%(1<<xx);
	while(S[u].size()){
		set<int>::iterator s=S[u].begin();
		if(g[ff(((*s)+1)/2)]){
			S[u].erase((*s));
			continue;
		}
		solve((*s),xx);
		break;
	}
	solve(to[y],xx);
}
void print(int x){
	printf("%d\n",x);
	if(!x){
		rep(i,2*n)printf("%d ",i);
		puts("");
		return;
	}
	rep0(i,(1<<x))sm[i]=-1;
	rep(i,n){
		if(~sm[A[i]%(1<<x)]){
			to[sm[A[i]%(1<<x)]]=i*2-1;
			to[i*2-1]=sm[A[i]%(1<<x)];
			sm[A[i]%(1<<x)]=-1;
		}
		else sm[A[i]%(1<<x)]=i*2-1;
		if(~sm[B[i]%(1<<x)]){
			to[sm[B[i]%(1<<x)]]=i*2;
			to[i*2]=sm[B[i]%(1<<x)];
			sm[B[i]%(1<<x)]=-1;
		}
		else sm[B[i]%(1<<x)]=i*2;
	}
	rep(i,n){
		S[A[i]%(1<<x)].insert(i*2-1);
		S[B[i]%(1<<x)].insert(i*2);
	}
	rep(i,n)f[i]=i;
	rep(i,n){
		if(ff(i)!=ff((to[i*2-1]+1)/2))f[ff(i)]=ff((to[i*2-1]+1)/2);
		if(ff(i)!=ff((to[i*2]+1)/2))f[ff(i)]=ff((to[i*2]+1)/2);
	}
	rep(i,n)g[i]=0;
	rep(i,n*2)h[i]=0;
	solve(1,x);
	puts("");
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&A[i],&B[i]);
	int l=0,r=20;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(check(r))print(r);
	else print(l);
	return 0;
}