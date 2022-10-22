#include<bits/stdc++.h>
using namespace std;
#define N 400000
#define A 60
#define pb push_back
int n,a[N+1],dfn[N+1],nowdfn,mxdfn[N+1],mng[N+1];
vector<int> nei[N+1];
void dfs(int x=1,int fa=0){
	dfn[x]=mxdfn[x]=++nowdfn;mng[nowdfn]=x;
	for(int i=0;i<nei[x].size();i++){
		int to=nei[x][i];
		if(to==fa)continue;
		dfs(to,x);
		mxdfn[x]=max(mxdfn[x],mxdfn[to]);
	}
}
struct node{int l,r,lz;bitset<A+1> c;}nd[N<<2];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define lz(x) nd[x].lz
#define c(x) nd[x].c
void bld(int l=1,int r=n,int p=1){
	l(p)=l;r(p)=r;lz(p)=0;
	if(l==r){c(p).reset();c(p).set(a[mng[l]]);return;}
	int mid=l+r>>1;
	bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	c(p)=c(p<<1)|c(p<<1|1);
}
void spr(int p){
	if(lz(p)){
		int x=lz(p);lz(p)=0;
		lz(p<<1)=lz(p<<1|1)=x;
		c(p<<1).reset();c(p<<1).set(x);c(p<<1|1).reset();c(p<<1|1).set(x);
	}
}
void chg(int l,int r,int v,int p=1){
	if(l<=l(p)&&r>=r(p)){c(p).reset();c(p).set(v);lz(p)=v;return;}
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)chg(l,r,v,p<<1);
	if(r>mid)chg(l,r,v,p<<1|1);
	c(p)=c(p<<1)|c(p<<1|1);
}
bitset<A+1> ask(int l,int r,int p=1){
	if(l<=l(p)&&r>=r(p))return c(p);
	spr(p);
	int mid=l(p)+r(p)>>1;
	bitset<A+1> res;res.reset();
	if(l<=mid)res|=ask(l,r,p<<1);
	if(r>mid)res|=ask(l,r,p<<1|1);
	return res;
}
int main(){
	int qu,i;scanf("%d%d",&n,&qu);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	bld();
	while(qu--){
		int tp,x,y;scanf("%d%d",&tp,&x);
		if(tp==1)scanf("%d",&y),chg(dfn[x],mxdfn[x],y);
		else printf("%d\n",ask(dfn[x],mxdfn[x]).count());
	}
	return 0;
}
/*1
7 10
1 1 1 1 1 1 1
1 2
1 3
1 4
3 5
3 6
3 7
1 3 2
2 1
1 4 3
2 1
1 2 5
2 1
1 6 4
2 1
2 2
2 3
*/
/*2
23 30
1 2 2 6 5 3 2 1 1 1 2 4 5 3 4 4 3 3 3 3 3 4 6
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
4 11
6 12
6 13
7 14
7 15
7 16
8 17
8 18
10 19
10 20
10 21
11 22
11 23
2 1
2 5
2 6
2 7
2 8
2 9
2 10
2 11
2 4
1 12 1
1 13 1
1 14 1
1 15 1
1 16 1
1 17 1
1 18 1
1 19 1
1 20 1
1 21 1
1 22 1
1 23 1
2 1
2 5
2 6
2 7
2 8
2 9
2 10
2 11
2 4
*/