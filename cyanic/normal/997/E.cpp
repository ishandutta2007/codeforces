#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=120005;
struct node{
	int mn,cnt,tag;
	ll sum,c;
}T[N<<2];
int	p[N],s1[N],s2[N],t1,t2,n,Q,x,y;
vector<pii> q[N];
ll ans[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void build(int o,int l,int r){
	T[o].mn=l,T[o].cnt=1;
	if(l!=r) build(lc,l,mid),build(rc,mid+1,r);
}
void down(int o){
	if(T[o].tag){
		T[lc].mn+=T[o].tag,T[lc].tag+=T[o].tag;
		T[rc].mn+=T[o].tag,T[rc].tag+=T[o].tag;
		T[o].tag=0;
	}
	if(T[o].c){
		if(T[o].mn==T[lc].mn){
			T[lc].sum+=T[lc].cnt*T[o].c;
			T[lc].c+=T[o].c;
		}
		if(T[o].mn==T[rc].mn){
			T[rc].sum+=T[rc].cnt*T[o].c;
			T[rc].c+=T[o].c;
		}
		T[o].c=0;
	}
}
void up(int o){
	T[o].mn=min(T[lc].mn,T[rc].mn),T[o].cnt=0;
	if(T[o].mn==T[lc].mn) T[o].cnt+=T[lc].cnt;
	if(T[o].mn==T[rc].mn) T[o].cnt+=T[rc].cnt;
	T[o].sum=T[lc].sum+T[rc].sum;
}
void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		T[o].mn+=z,T[o].tag+=z;
		return;
	}
	down(o);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	up(o);
}
ll qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r) return T[o].sum;
	down(o);
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	return qry(lc,l,mid,x,mid)+qry(rc,mid+1,r,mid+1,y);
}

int main(){
	read(n);
	rep(i,1,n) read(p[i]);
	read(Q);
	rep(i,1,Q){
		read(x),read(y);
		q[y].pb(mp(i,x));
	}
	build(1,1,n);
	rep(i,1,n){
		T[1].mn-=1,T[1].tag-=1;
		for(;t1&&p[i]>p[s1[t1]];t1--)
			upd(1,1,n,s1[t1-1]+1,s1[t1],p[i]-p[s1[t1]]);
		s1[++t1]=i;
		for(;t2&&p[i]<p[s2[t2]];t2--)
			upd(1,1,n,s2[t2-1]+1,s2[t2],p[s2[t2]]-p[i]);
		s2[++t2]=i;
		T[1].sum+=T[1].cnt,T[1].c+=1;
		for(auto x:q[i]) ans[x.fi]=qry(1,1,n,x.se,i);
	}
	rep(i,1,Q) printf("%lld\n",ans[i]);
	return 0;
}