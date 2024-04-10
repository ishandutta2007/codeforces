#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
const ld inf=1e99,eps=1e-8;
struct node{
	ld win,lose; int x,y;
}T[N<<2];
int a[N],b[N],n,t,Q;
ld p[N],ans;

void up(int o){
	int p=(T[lc].win>T[rc].win?lc:rc);
	T[o].win=T[p].win,T[o].x=T[p].x;
	p=(T[lc].lose<T[rc].lose?lc:rc);
	T[o].lose=T[p].lose,T[o].y=T[p].y;
}
void build(int o,int l,int r){
	if(l==r){
		T[o].win=p[l]/(a[l]+1);
		T[o].lose=inf;
		T[o].x=T[o].y=l;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(o);
}
void upd(int o,int l,int r,int x,int y,int ty){
	if(l==r){
		ans-=p[x]/(a[x]+b[x])*b[x];
		if(ty==0)b[x]+=y,t-=y;else a[x]+=y;
		ans+=p[x]/(a[x]+b[x])*b[x];
		if(b[x]==0)T[o].lose=inf;
		else{
			T[o].lose=p[x]/(a[x]+b[x])*b[x]
					 -p[x]/(a[x]+b[x]-1)*(b[x]-1);
		}
		if(b[x]==a[x])T[o].win=0;
		else{
			T[o].win=p[x]/(a[x]+b[x]+1)*(b[x]+1)
					-p[x]/(a[x]+b[x])*b[x];
		}
		return;
	}
	if(x<=mid)upd(lc,l,mid,x,y,ty);
	else upd(rc,mid+1,r,x,y,ty);
	up(o);
}

int main(){
	read(n),read(t),read(Q);
	rep(i,1,n)read(p[i]);
	rep(i,1,n)read(a[i]);
	build(1,1,n);
	while(t&&T[1].win>eps)
		upd(1,1,n,T[1].x,1,0);
	while(Q--){
		int A,B;
		read(A),read(B);
		if(A==1)upd(1,1,n,B,1,1);
		else{
			upd(1,1,n,B,-1,1);
			while(b[B]>a[B])upd(1,1,n,B,-1,0);
		}
		for(;;){
			if(T[1].win>T[1].lose){
				A=T[1].x,B=T[1].y;
				upd(1,1,n,A,1,0),upd(1,1,n,B,-1,0);
			}
			else if(t&&T[1].win>eps){
				upd(1,1,n,T[1].x,1,0);
			}
			else break;
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}