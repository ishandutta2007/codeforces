#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=500005,inf=1e9+99;
int T[N<<2],S[N<<2],lzy[N<<2];
int ans[N],p[N],n;
vi rev[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void build(int o,int l,int r){
	S[o]=l,T[o]=lzy[o]=0;
	if(l==r)return;
	build(lc,l,mid),build(rc,mid+1,r);
}
inline void up(int o){
	if(T[lc]<=T[rc])T[o]=T[lc],S[o]=S[lc];
	else T[o]=T[rc],S[o]=S[rc];
}
inline void app(int o,int x){
	T[o]+=x,lzy[o]+=x;
}
inline void down(int o){
	if(!lzy[o])return;
	app(lc,lzy[o]),app(rc,lzy[o]);
	lzy[o]=0;
}
void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r)return app(o,z);
	down(o);
	if(x<=mid)upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y)upd(rc,mid+1,r,max(mid+1,x),y,z);
	up(o);
}

void MAIN(){
	scanf("%d",&n);
	build(1,1,n);
	rep(i,1,n)rev[i].clear();
	rep(i,1,n){
		scanf("%d",&p[i]);
		if(p[i]!=-1)upd(1,1,n,i,p[i]-1,1),rev[p[i]].pb(i);
		if(p[i]==n+1)upd(1,1,n,i,i,-1);
	}
	rep(i,1,n){
		if(T[1])return (void)puts("-1");
		int x=S[1];
		ans[x]=n+1-i;
		if(x+1<=p[x]-1)upd(1,1,n,x+1,p[x]-1,-1);
		for(auto y:rev[x])
			upd(1,1,n,y,y,-1);
		upd(1,1,n,x,x,inf);
	}
	rep(i,1,n)printf("%d ",ans[i]);
	puts("");
}

int main(){
	int T;scanf("%d",&T);
	while(T--)MAIN();
	return 0;
}