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
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 203333, M = 330, off=M;
int n,q,fa[N],a[N],b[N],top[N],Q[N],ans,lzy[N];Vi e[N];//ans=\sum_ [a_i>0]
bool mrk[N];int bh[N],cnt;
int buc[M*2+3][M*2+3],pos[M*2+3],Real[N];
int newf[N],dfn[N],num,newa[N];//u-->dfn[u]
void dfs(int u, int fa){
	dfn[u]=++num;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs(e[u][i],u);
}
int main() {
	read(n);read(q);
	rep(i,2,n)read(fa[i]),e[fa[i]].pb(i);
	rep(i,1,n)read(a[i]),a[i]=-a[i];
	rep(i,1,q)read(Q[i]),Q[i]=Q[i]>0?Q[i]:-Q[i];
	dfs(1,0);
	rep(i,1,q)Q[i]=dfn[Q[i]];
	rep(i,2,n)newf[dfn[i]]=dfn[fa[i]];
	rep(i,2,n)fa[i]=newf[i];
	rep(i,1,n)newa[dfn[i]]=a[i];
	rep(i,1,n)a[i]=newa[i];
	
	for(int l=1;l<=q;l+=M){
		int r=min(q,l+M-1);
		memset(lzy,0,4*(n+2));memset(mrk,0,(n+2));
		rep(k,l,r)lzy[Q[k]]=mrk[Q[k]]=1;
		per(i,n,1){
			mrk[i]|=lzy[i]>=2||i==1;
			lzy[fa[i]]+=lzy[i]>0;
		}
	//	rep(i,1,n)cerr<<mrk[i]<<' ';cerr<<endl;
	//	rep(i,1,n)cerr<<a[i]<<' ';cerr<<endl;
		rep(i,1,n){
			top[i]=mrk[fa[i]]?fa[i]:top[fa[i]];
		}
		cnt=0;
		rep(i,1,n)if(mrk[i]){
			bh[i]=++cnt;pos[cnt]=1;//pos[cnt]..inf
			for(int j=fa[i];j!=top[i]&&j;j=fa[j])if(!b[j]&&a[j]>=-M&&a[j]<=M)buc[cnt][a[j]+off]++;
		}
		memset(lzy,0,4*(n+2));memcpy(Real,a,4*(n+2));
		rep(k,l,r){
			for(int u=Q[k];u;u=top[u]){
				if(!b[Q[k]])ans+=buc[bh[u]][pos[bh[u]]-1+off],pos[bh[u]]--;
				else ans-=buc[bh[u]][pos[bh[u]]+off],pos[bh[u]]++;
			}
			ans-=(!b[Q[k]]&&Real[Q[k]]>0);ans+=(b[Q[k]]&&Real[Q[k]]+(!b[Q[k]]?1:-1)>0);Real[Q[k]]+=!b[Q[k]]?1:-1;
			for(int u=top[Q[k]];u;u=top[u]){
				if(!b[u]){ans-=(Real[u]>0);ans+=(Real[u]+(!b[Q[k]]?1:-1)>0);}
				Real[u]+=!b[Q[k]]?1:-1;
			}
			if(!b[Q[k]])lzy[Q[k]]++;else lzy[Q[k]]--;b[Q[k]]^=1;
			printf("%d ",ans);
		}
		//recover!!!!
		rep(i,1,n)if(mrk[i]){
			for(int j=fa[i];j!=top[i]&&j;j=fa[j])if(a[j]>=-M&&a[j]<=M)buc[bh[i]][a[j]+off]=0;
			bh[i]=0;
		}
		rep(i,1,cnt)pos[i]=0;
		//rebuild
		per(i,n,1)lzy[fa[i]]+=lzy[i],a[i]+=lzy[i];
	}
	return 0;
}