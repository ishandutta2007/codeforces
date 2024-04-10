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
const int N=3e5+7;
const int INF=1e9+7;
int n,q;
int p[N];
struct pir{int l,r,v;};
vector<pir>d[N*4];
int check(int p,int v){
	int l=0,r=d[p].size()-1;
	if(l==r)return d[p][0].v;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(v>=d[p][mid].l)l=mid;
		else r=mid;
	}
	if(v>=d[p][r].l)return d[p][r].v;
	return d[p][l].v;
}
void mer(int x){
	int ls=0;
	rep0(i,d[x*2].size()){
		int hl=d[x*2][i].l+d[x*2][i].v,hr=d[x*2][i].r+d[x*2][i].v;
		while(ls<d[x*2+1].size()&&d[x*2+1][ls].r<hl)ls++;
		if(ls>=d[x*2+1].size()){
			d[x].push_back((pir){d[x*2][i].l,d[x*2][i].r,d[x*2][i].v});
			continue;
		}
		while(ls<d[x*2+1].size()&&d[x*2+1][ls].r<hr){
			d[x].push_back((pir){max(hl,d[x*2+1][ls].l)-d[x*2][i].v,d[x*2+1][ls].r-d[x*2][i].v,d[x*2][i].v+d[x*2+1][ls].v});
			ls++;
		}
		if(ls>=d[x*2+1].size()){
			d[x].push_back((pir){(d[x*2+1][d[x*2+1].size()-1].r+1)-d[x*2][i].v,d[x*2][i].r,d[x*2][i].v});
			continue;
		}
		d[x].push_back((pir){max(hl,d[x*2+1][ls].l)-d[x*2][i].v,d[x*2][i].r,d[x*2][i].v+d[x*2+1][ls].v});
	}
} 
void build(int l,int r,int v){
	if(l==r){
		if(p[l]>l)d[v].push_back((pir){0,n,0});
		else{
			if(p[l]==l)d[v].push_back((pir){0,n,1});
			else{
				d[v].push_back((pir){0,l-p[l]-1,0});
				d[v].push_back((pir){l-p[l],n,1});
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,v*2);
	build(mid+1,r,v*2+1);
	mer(v);
}
int solve(int L,int R,int l,int r,int v,int d){
	if(L<=l&&R>=r)return d+check(v,d);
	int mid=(l+r)>>1;
	if(L<=mid){
		if(R>mid){
			int t=solve(L,R,l,mid,v*2,d);
			return solve(L,R,mid+1,r,v*2+1,t);
		}
		return solve(L,R,l,mid,v*2,d);
	}
	return solve(L,R,mid+1,r,v*2+1,d);
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n)scanf("%d",&p[i]);
	build(1,n,1);
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",solve(x+1,n-y,1,n,1,0));
	}
	return 0;
}