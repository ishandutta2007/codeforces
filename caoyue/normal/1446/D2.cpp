#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
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
int n;
int a[N],w[N],c[N],s[N];
vector<int>h[N];
map<int,int>mp;
void Ins(int x,int y){
	map<int,int>::iterator u=mp.upper_bound(x);
	if(u!=mp.begin()){
		u--;
		if((u->second)<=y)return;
	}
	mp[x]=y;
	while(1){
		map<int,int>::iterator g=mp.upper_bound(x);
		if(g==mp.end())break;
		if((g->second)>y)mp.erase(g->first);
		else break;
	}
}
struct Tree{int l,r,mx;}tr[N*4];
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
void ins(int p,int L,int R,int v){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].mx=max(tr[p].mx,v);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)ins(p*2,L,R,v);
	if(R>mid)ins(p*2+1,L,R,v);
}
int check(int p,int x){
	if(tr[p].l==tr[p].r)return tr[p].mx;
	int mid=(tr[p].l+tr[p].r)>>1;
	if(x<=mid)return max(check(p*2,x),tr[p].mx);
	else return max(check(p*2+1,x),tr[p].mx);
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int nm=0,nx,mi=n+1;
	for(int i=n;i;i--){
		c[w[a[i]]]--;
		w[a[i]]++;
		c[w[a[i]]]++;
		if(w[a[i]]>nm){
			nm=w[a[i]];
			nx=a[i];
		}
		if(c[nm]>1)mi=i;
	}
	int Ans=n-mi+1;
	rep(i,n)s[i]=s[i-1]+(a[i]==nx);
	rep(i,n)h[a[i]].push_back(i);
	build(0,s[n],1);
	rep(i,n){
		if(i==nx)continue;
		if(!h[i].size())continue;
		mp.clear();
		rep0(j,h[i].size()){
			int v=j-s[h[i][j]-1];
			Ins(v,j);
			int u=j+1-s[h[i][j]];
			int q=j+1-((j!=h[i].size()-1)?s[h[i][j+1]]:INF);
			map<int,int>::iterator o=mp.upper_bound(u);
			while(o!=mp.begin()){
				o--;
				if((o->first)<q)break;
				int t2=o->second;
				int p=j-t2+1,e=s[h[i][j]],b=s[h[i][t2]]+1;
				if(e-p+1<=b)ins(1,e-p+1,b,p);
			}
		}
	}
	rep0(i,h[nx].size()){
		int u=check(1,i+1);
		u=min(u,(int)h[nx].size()-i);
		int pe=(i+u==h[nx].size())?n:h[nx][i+u]-1;
		Ans=max(Ans,pe-(i?h[nx][i-1]:0));
	}
	printf("%d\n",Ans);
	return 0;
}