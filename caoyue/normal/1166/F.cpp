#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
int cnt,n,m,q,C,num=0;
struct wt{int op,x,y,c;}w[N];
map<int,int>S[N];
struct Tree{int sm,ls,rs;}tr[N*23];
int fa[N],rt[N],bg[N],ed[N];
int ff(int x){return (fa[x]==x)?x:fa[x]=ff(fa[x]);}
int build(int l,int r,int x){
	tr[++num]=(Tree){1,0,0};
	if(l==r)return num;
	int mid=(l+r)>>1,p=num;
	if(x<=mid)tr[p].ls=build(l,mid,x);
	else tr[p].rs=build(mid+1,r,x);
	return p;
}
int mer(int x,int y){
	if(!x||!y)return x+y;
	tr[x].sm+=tr[y].sm;
	tr[x].ls=mer(tr[x].ls,tr[y].ls);
	tr[x].rs=mer(tr[x].rs,tr[y].rs);
	return x;
}
int check(int p,int l,int r,int L,int R){
	if(!p)return 0;
	if(L<=l&&R>=r)return tr[p].sm;
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)ans+=check(tr[p].ls,l,mid,L,R);
	if(R>mid) ans+=check(tr[p].rs,mid+1,r,L,R);
	return ans;
}
void merge(int x,int y){
	int a=ff(x),b=ff(y);
	if(a==b)return;
	rt[a]=mer(rt[a],rt[b]);
	fa[b]=a;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&C,&q);
	cnt=n;
	rep(i,m){
		w[i].op=1;
		scanf("%d%d%d",&w[i].x,&w[i].y,&w[i].c);
		S[w[i].x][w[i].c]=1;
		S[w[i].y][w[i].c]=1;
	}
	rep(i,q){
		char c[9]; scanf("%s",c);
		if(c[0]=='+'){
			w[i+m].op=1;
			scanf("%d%d%d",&w[i+m].x,&w[i+m].y,&w[i+m].c);
			S[w[i+m].x][w[i+m].c]=1;
			S[w[i+m].y][w[i+m].c]=1;
		}
		else{
			w[i+m].op=0;
			scanf("%d%d",&w[i+m].x,&w[i+m].y);
		}
	}
	rep(i,n){
		map<int,int>::iterator g=S[i].begin();
		bg[i]=cnt+1;
		for(;g!=S[i].end();g++)S[i][g->first]=++cnt;
		ed[i]=cnt;
	}
	rep(i,cnt){
		fa[i]=i;
		rt[i]=build(1,cnt,i);
	}
	rep(i,m+q){
		if(w[i].op){
			merge(w[i].x,S[w[i].y][w[i].c]);
			merge(w[i].y,S[w[i].x][w[i].c]);
		}
		else{
			int t=rt[ff(w[i].x)];
			if(check(t,1,cnt,w[i].y,w[i].y))puts("Yes");
			else{
				if(bg[w[i].y]>ed[w[i].y])puts("No");
				else if(check(t,1,cnt,bg[w[i].y],ed[w[i].y]))puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}