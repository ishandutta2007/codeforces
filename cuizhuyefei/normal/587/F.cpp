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
const int N = 102000,M=300;
int n,q,dl[N],dr[N],A[N],B[N],C[N],endpos[N],num,idfn[N];Vi dot[N];char s[N];ll ans[N];
Vi que1[N],que[N],e[N];
int ch[N][26],tot,fa[N];
void dfs1(int u){
	dl[u]=++num;idfn[num]=u;
	rep(i,0,SZ(e[u])-1)dfs1(e[u][i]);
	dr[u]=num;
}
void ini(){
	static int q[N];int f=0,r=0;
	rep(i,0,25)if(ch[0][i])q[r++]=ch[0][i];
	while(f!=r){
		int u=q[f++];
		rep(i,0,25)if(ch[u][i]){
			int v=ch[u][i];q[r++]=v;
			int x=fa[u];while(x&&!ch[x][i])x=fa[x];
			fa[v]=ch[x][i];
		}
	}
	rep(i,1,tot)e[fa[i]].pb(i);
	dfs1(0);
}
int Abs(int x){return x>0?x:-x;}
int sgn(int x){return x>0?1:-1;}
int lzy[N/M+5],val[N],bel[N],bg[N],ed[N];
inline void modify(int k, int l, int r){rep(i,l,r)val[i]++;}
inline void modify(int l, int r){
	if(bel[l]==bel[r])modify(bel[l],l,r);
	else{
		modify(bel[l],l,ed[bel[l]]);modify(bel[r],bg[bel[r]],r);
		rep(i,bel[l]+1,bel[r]-1)lzy[i]++;
	}
}
inline int qry(int x){
	return val[x]+lzy[bel[x]];
}
int main() {
	read(n);read(q);
	rep(i,1,n){
		scanf("%s",s+1);int len=strlen(s+1);
		for(int j=1,u=0;j<=len;j++){
			if(!ch[u][s[j]-'a'])ch[u][s[j]-'a']=++tot;
			u=ch[u][s[j]-'a'];dot[i].pb(u);
		}
		endpos[i]=dot[i].back();
	}
	ini();
	rep(i,1,q){
		read(A[i]),read(B[i]),read(C[i]);
		if(SZ(dot[C[i]])>=M)que1[C[i]].pb(i);
		else que[B[i]].pb(i),que[A[i]-1].pb(-i);
	}
	rep(i,1,n)if(SZ(que1[i])){
		static int v[N];static ll qz[N];
		memset(v,0,sizeof(v));
		rep(j,0,SZ(dot[i])-1)v[dot[i][j]]++;
		per(j,num,1)v[fa[idfn[j]]]+=v[idfn[j]];
		rep(j,1,n)qz[j]=qz[j-1]+v[endpos[j]];
		rep(j,0,SZ(que1[i])-1)ans[que1[i][j]]=qz[B[que1[i][j]]]-qz[A[que1[i][j]]-1];
	}
	rep(i,1,num)bel[i]=i/M,ed[bel[i]]=i;
	per(i,num,1)bg[bel[i]]=i;
//	rep(k,0,SZ(dot[4])-1)cerr<<dl[dot[4][k]]<<endl;
	rep(i,1,n){
		modify(dl[endpos[i]],dr[endpos[i]]);
	//	cerr<<i<<' '<<dl[endpos[i]]<<' '<<dr[endpos[i]]<<endl;
		rep(j,0,SZ(que[i])-1){
			int u=C[Abs(que[i][j])];ll c=0;rep(k,0,SZ(dot[u])-1)c+=qry(dl[dot[u][k]]);
			ans[Abs(que[i][j])]+=sgn(que[i][j])*c;
		}
	}
	rep(i,1,q)printf("%lld\n",ans[i]);
	return 0;
}