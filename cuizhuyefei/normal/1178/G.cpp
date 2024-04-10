#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,ll> Pil;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
const int N = 233333,M = 160;
int n,Q,a[N],b[N],fa[N],OP[N],A[N],B[N],dl[N],dr[N],num;ll ans[N];Vi e[N];
int bel[N],bg[N/M+5],ed[N/M+5],c[N],lzy[N/M+5];ll d[N];//cx+d
void dfs(int u){
	dl[u]=++num;
	rep(i,0,SZ(e[u])-1)dfs(e[u][i]);
	dr[u]=num;
}
int s[N];Pil q[N];int f[N/M+5],r[N/M+5];
bool cmp(int x, int y){return c[x]<c[y];}
inline ll sgn(ll x){return x==0?0:(x>0?1:-1);}
/*inline double Cross(const Pil&a,const Pil&b){
	return 1.0*a.fi*b.se-1.0*a.se*b.fi;
}*/
inline bool Cross(const Pil&a,const Pil&b){
	if(!b.fi)return sgn(a.fi)*sgn(b.se)>=0;
	if(!a.fi)return -sgn(a.se)*sgn(b.fi)>=0;
	assert(a.fi>0&&b.fi>0);
	return 1.0*b.se/b.fi>=1.0*a.se/a.fi;
}
inline Pil operator-(const Pil&a,const Pil&b){return Pil(a.fi-b.fi,a.se-b.se);}
inline void build(int k){
	if(lzy[k]){
		rep(i,bg[k],ed[k])d[i]+=1LL*lzy[k]*c[i];lzy[k]=0;
	}
	f[k]=bg[k];r[k]=bg[k]-1;
	rep(i,bg[k],ed[k]){
		Pil tmp=Pil(c[s[i]],d[s[i]]);
		while(r[k]-f[k]+1>=2&&Cross(q[r[k]]-q[r[k]-1],tmp-q[r[k]]))r[k]--;
		q[++r[k]]=tmp;
	}
}
inline ll calc(Pil a, int x){return 1LL*a.fi*x+a.se;}
bool TP;
inline ll query(int k){
	if(!TP){
		while(r[k]-f[k]+1>=2&&calc(q[f[k]],lzy[k])<=calc(q[f[k]+1],lzy[k]))f[k]++;
		return calc(q[f[k]],lzy[k]);
	}
	while(r[k]-f[k]+1>=2&&calc(q[r[k]],lzy[k])<=calc(q[r[k]-1],lzy[k]))r[k]--;
	return calc(q[r[k]],lzy[k]);
}
void solve(){
	rep(i,1,n)c[dl[i]]=b[i],d[dl[i]]=1LL*a[i]*b[i],s[i]=i;
	rep(i,1,n)bel[i]=i/M;
	rep(i,1,n)ed[bel[i]]=i;
	per(i,n,1)bg[bel[i]]=i;
	rep(i,bel[1],bel[n])sort(s+bg[i],s+ed[i]+1,cmp),lzy[i]=0;
	rep(i,bel[1],bel[n])build(i);
//	rep(i,1,n)printf("%d:%d %d\n",i,c[i],d[i]);
	rep(t,1,Q)
		if(OP[t]==1){
			int l=dl[A[t]],r=dr[A[t]],x=B[t];
		//	printf("m %d %d %d\n",l,r,x);
			if(bel[l]==bel[r]){rep(i,l,r)d[i]+=1LL*c[i]*x;build(bel[l]);}
			else{
				rep(i,l,ed[bel[l]])d[i]+=1LL*c[i]*x;build(bel[l]);
				rep(i,bg[bel[r]],r)d[i]+=1LL*c[i]*x;build(bel[r]);
				rep(i,bel[l]+1,bel[r]-1)lzy[i]+=x;
			}
		}
		else{
			int l=dl[A[t]],r=dr[A[t]];
		//	printf("q %d %d\n",l,r);
			if(bel[l]==bel[r]){rep(i,l,r)umax(ans[t],d[i]+1LL*c[i]*lzy[bel[i]]);}
			else{
				rep(i,l,ed[bel[l]])umax(ans[t],d[i]+1LL*c[i]*lzy[bel[i]]);
				rep(i,bg[bel[r]],r)umax(ans[t],d[i]+1LL*c[i]*lzy[bel[i]]);
				rep(i,bel[l]+1,bel[r]-1)umax(ans[t],query(i));
			}
		}
}
int main() {
	read(n);read(Q);rep(i,2,n)read(fa[i]),e[fa[i]].pb(i);
	dfs(1);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	rep(i,1,Q){
		read(OP[i]),read(A[i]);
		if(OP[i]==1)read(B[i]);
	}
	rep(i,2,n)a[i]+=a[fa[i]],b[i]+=b[fa[i]];
	rep(i,1,n)b[i]=b[i]>0?b[i]:-b[i];
	solve();
	rep(i,1,n)a[i]=-a[i];
	rep(i,1,Q)if(OP[i]==1)B[i]=-B[i];
	TP=1;solve();
	rep(i,1,Q)if(OP[i]==2)printf("%lld\n",ans[i]);
	return 0;
}