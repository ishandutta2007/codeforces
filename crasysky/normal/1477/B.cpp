#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6;
struct node{ int l,r,tag,s; }tr[N];
char s[N],t[N];
void build(int rt,int l,int r){
	tr[rt].l=l,tr[rt].r=r,tr[rt].tag=-1;
	if (l==r){ tr[rt].s=t[l]-'0'; return; }
	int m=l+r>>1; build(rt<<1,l,m),build(rt<<1|1,m+1,r);
	tr[rt].s=tr[rt<<1].s+tr[rt<<1|1].s;
}
void upd(int rt,int t){
	tr[rt].tag=t,tr[rt].s=t?tr[rt].r-tr[rt].l+1:0;
}
void down(int rt){
	if (~tr[rt].tag){
		upd(rt<<1,tr[rt].tag),upd(rt<<1|1,tr[rt].tag);
		tr[rt].tag=-1;
	}
}
int sum(int rt,int l,int r){
	if (tr[rt].r<l||r<tr[rt].l) return 0;
	if (l<=tr[rt].l&&tr[rt].r<=r) return tr[rt].s;
	down(rt); return sum(rt<<1,l,r)+sum(rt<<1|1,l,r);
}
void st(int rt,int l,int r,int x){
	if (tr[rt].r<l||r<tr[rt].l) return;
	if (l<=tr[rt].l&&tr[rt].r<=r){ upd(rt,x); return; }
	down(rt),st(rt<<1,l,r,x),st(rt<<1|1,l,r,x);
	tr[rt].s=tr[rt<<1].s+tr[rt<<1|1].s;
}
int l[N],r[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,q; scanf("%d%d",&n,&q);
		scanf("%s%s",s,t);
		build(1,0,n-1);
		rep(i,1,q) scanf("%d%d",&l[i],&r[i]),--l[i],--r[i];
		bool f=false;
		per(i,q,1){
			int s=sum(1,l[i],r[i]),len=r[i]-l[i]+1;
			if (2*s<len) st(1,l[i],r[i],0);
			else if (2*(len-s)<len) st(1,l[i],r[i],1);
			else{ f=true; break; }
		}
		rep(i,0,n-1) if (sum(1,i,i)!=s[i]-'0'){ f=true; break; }
		puts(!f?"YES":"NO");
	}
	return 0;
}