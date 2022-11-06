#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
struct node{
	int s;
	pa p[6];
}T[600010],ans;
pa tmp[600010];
int n,m,l,r,x,tp,L,p,ts,tag[600010],a[600010];
node merge(node A,node B){
	if (A.s==0) return B;
	FOR(i,1,B.s){
		bool ok=0;
		FOR(j,1,A.s)
			if (A.p[j].fi==B.p[i].fi){ok=1;A.p[j].se+=B.p[i].se;}
		if (ok) continue;
		if (A.s<L){
			A.p[++A.s]=B.p[i];
			continue;
		}
		A.p[0]=B.p[i];
		int t=A.p[0].se;
		FOR(j,1,A.s) t=min(t,A.p[j].se);
		FOR(j,0,A.s) A.p[j].se-=t;
		int ts=0;
		FOR(j,0,A.s)
			if (A.p[j].se) tmp[++ts]=A.p[j];
		A.s=ts;
		FOR(j,1,A.s) A.p[j]=tmp[j];
	}
	return A;
}
void build(int l,int r,int rt){
	if (l==r){
		T[rt].s=1;
		T[rt].p[1]=mp(a[l],1);
		return;
	}
	int m=l+r>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	T[rt]=merge(T[rt<<1],T[rt<<1|1]);
}
void TAG(int l,int r,int rt,int x){
	T[rt].s=1;
	T[rt].p[1]=mp(x,r-l+1);
	tag[rt]=x;
}
void pushdown(int l,int r,int rt){
	if (tag[rt]){
		int m=l+r>>1;
		TAG(l,m,rt<<1,tag[rt]);
		TAG(m+1,r,rt<<1|1,tag[rt]);
		tag[rt]=0;
	}
}
void upd(int l,int r,int rt,int L,int R,int x){
	if (l>=L && r<=R){
		TAG(l,r,rt,x);
		return;
	}
	int m=l+r>>1;
	pushdown(l,r,rt);
	if (L<=m) upd(l,m,rt<<1,L,R,x);
	if (R>m) upd(m+1,r,rt<<1|1,L,R,x);
	T[rt]=merge(T[rt<<1],T[rt<<1|1]);
}
void que(int l,int r,int rt,int L,int R){
	if (l>=L && r<=R){
		ans=merge(ans,T[rt]);
		return;
	}
	pushdown(l,r,rt);
	int m=l+r>>1;
	if (L<=m) que(l,m,rt<<1,L,R);
	if (R>m) que(m+1,r,rt<<1|1,L,R);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	L=100/p;
	FOR(i,1,n) getint(a[i]);
	build(1,n,1);
	FOR(i,1,m){
		getint(tp);
		if (tp==1){
			getint(l),getint(r),getint(x);
			upd(1,n,1,l,r,x);
		}
		else{
			getint(l),getint(r);
			ans.s=0;
			que(1,n,1,l,r);
			printf("%d ",ans.s);
			FOR(j,1,ans.s) printf("%d ",ans.p[j].fi);
			puts("");
		}
	}
	return 0;
}