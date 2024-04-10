#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=400005;
ll t[N],v[N],u[N],mn[N],bad[50];
int cnt,n,Q,op,l,r,a,b;

inline ll getmn(ll x){
	int t=lower_bound(bad+1,bad+cnt+1,x)-bad;
	return bad[t]-x;
}

void build(int o,int l,int r){
	if(l==r){
		v[o]=t[l];
		mn[o]=getmn(v[o]);
		return;
	}
	build(lc,l,mid),build(rc,mid+1,r);
	mn[o]=min(mn[lc],mn[rc]);
}

void down(int o){
	if(v[o]){
		v[lc]=v[o],mn[lc]=mn[o],u[lc]=0;
		v[rc]=v[o],mn[rc]=mn[o],u[rc]=0;
		v[o]=u[o]=0;
	}
	else if(u[o]){
		if(v[lc])v[lc]+=u[o];
		mn[lc]-=u[o],u[lc]+=u[o];
		assert(mn[lc]>0);
		if(v[rc])v[rc]+=u[o];
		mn[rc]-=u[o],u[rc]+=u[o];
		assert(mn[rc]>0);
		u[o]=0;
	}
}

ll getval(int o,int l,int r,int x){
	if(l==r)return v[o];
	down(o);
	if(x<=mid)return getval(lc,l,mid,x);
	return getval(rc,mid+1,r,x);
}

void cover(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		v[o]=z,u[o]=0;
		mn[o]=getmn(v[o]);
		return;
	}
	down(o);
	if(x<=mid)cover(lc,l,mid,x,min(y,mid),z);
	if(mid<y)cover(rc,mid+1,r,max(mid+1,x),y,z);
	mn[o]=min(mn[lc],mn[rc]);
}

bool add(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r&&v[o]){
		v[o]+=z,u[o]=0;
		mn[o]=getmn(v[o]);
		return mn[o]==0;
	}
	if(l==x&&y==r&&mn[o]>z){
		mn[o]-=z,u[o]+=z;
		return 0;
	}
	int ret=0;down(o);
	if(x<=mid)ret|=add(lc,l,mid,x,min(y,mid),z);
	if(mid<y)ret|=add(rc,mid+1,r,max(mid+1,x),y,z);
	mn[o]=min(mn[lc],mn[rc]);
	return ret;
}

int main(){
	bad[cnt=1]=1;
	while(bad[cnt]<1e15)
		bad[cnt+1]=bad[cnt]*42,cnt++;
	read(n),read(Q);
	rep(i,1,n)read(t[i]);
	build(1,1,n);
	while(Q--){
		read(op);
		if(op==1){
			read(a);
			printf("%lld\n",getval(1,1,n,a));
		}
		else if(op==2){
			read(l),read(r),read(a);
			cover(1,1,n,l,r,a);
		}
		else{
			read(l),read(r),read(a);
			while(add(1,1,n,l,r,a));
		}
	}
	return 0;
}