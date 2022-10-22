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
const int N=2e5+7;
const int INF=1e9+7;
int T,n,q,gg;
char s[N],s0[N];
struct Tree{int l,r,s0,s1,lz;}tr[N*4];
int real0(int x){
	if(tr[x].lz<0)return tr[x].s0;
	if(tr[x].lz==0)return tr[x].r-tr[x].l+1;
	if(tr[x].lz==1)return 0;
}
int real1(int x){
	if(tr[x].lz<0)return tr[x].s1;
	if(tr[x].lz==1)return tr[x].r-tr[x].l+1;
	if(tr[x].lz==0)return 0;
}
void upd(int p){
	tr[p].s0=real0(p*2)+real0(p*2+1);
	tr[p].s1=real1(p*2)+real1(p*2+1);
}
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,0,0,-1};
	if(l==r){
		if(s[l]=='0')tr[p].s0=1;
		else tr[p].s1=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	upd(p);
}
struct pir{int a,b;};
pir mer(pir x,pir y){return (pir){x.a+y.a,x.b+y.b};}
void lzd(int p){
	if(tr[p].lz<0)return;
	tr[p].s0=real0(p);
	tr[p].s1=real1(p);
	tr[p*2].lz=tr[p].lz;
	tr[p*2+1].lz=tr[p].lz;
	tr[p].lz=-1;
}
pir check(int L,int R,int p){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return (pir){real0(p),real1(p)};
	int mid=(l+r)>>1;
	pir ans=(pir){0,0};
	lzd(p);
	if(L<=mid)ans=mer(ans,check(L,R,p*2));
	if(R>mid)ans=mer(ans,check(L,R,p*2+1));
	return ans;
}
void ins(int L,int R,int p,int v){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].lz=v;
		return;
	}
	int mid=(l+r)>>1;
	lzd(p);
	if(L<=mid)ins(L,R,p*2,v);
	if(R>mid)ins(L,R,p*2+1,v);
	upd(p);
}
void check(int p){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		int q0=real0(p),q1=real1(p);
		if(q0&&s0[l]=='1')gg=1;
		if(q1&&s0[l]=='0')gg=1;
		return;
	}
	lzd(p);
	check(p*2); check(p*2+1);
}
int u[N],v[N],g[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		scanf("%s",s0+1);
		scanf("%s",s+1);
		rep(i,q)scanf("%d%d",&u[i],&v[i]);
		rep(i,n)g[i]=0;
		rep(i,q)g[u[i]]++,g[v[i]+1]--;
		rep(i,n)g[i]+=g[i-1];
		bool sb=0;
		rep(i,n){
			if(!g[i]){
				if(s0[i]!=s[i]){
					sb=1;
					break;
				}
			}
		}
		if(sb){
			puts("NO");
			continue;
		}
		bool fl0=0,fl1=0;
		REP(i,u[1],v[1])if(s0[i]=='0')fl0=1;else fl1=1;
		if(fl0&&fl1){
			puts("NO");
			continue;
		}
		build(1,n,1);
		bool fl=0;
		for(int i=q;i;i--){
			pir o=check(u[i],v[i],1);
			if(o.a==o.b){
				fl=1;
				break;
			}
			if(o.a>o.b)ins(u[i],v[i],1,0);
			else ins(u[i],v[i],1,1);
		}
		gg=0;
		check(1);
		if(fl||gg)puts("NO");
		else puts("YES");
	}
	return 0;
}