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
const int N = 2020,mo=998244353;
int n,res;char s[N];
int bh[2][N],num,col[N];vector<Pii>e[N];bool gg;bool vis[N];
void dfs(int u){
	vis[u]=1;
	rep(i,0,SZ(e[u])-1)
		if(!vis[e[u][i].fi]){
		//	gg|=(col[e[u][i].fi]!=-1&&col[e[u][i].fi]!=(col[u]^e[u][i].se));
			col[e[u][i].fi]=col[u]^e[u][i].se,dfs(e[u][i].fi);
		}
		else gg|=col[e[u][i].fi]!=(col[u]^e[u][i].se);
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	reverse(s+1,s+n+1);//n..1
	if(s[1]=='1'){puts("0");return 0;}
	rep(m,1,n-1){
		num=0;rep(i,0,1)rep(j,1,n)bh[i][j]=0;
		rep(i,2,n-1)bh[0][i]=++num;
		rep(i,2,m-1)bh[1][i]=++num;
		rep(i,1,num)col[i]=-1,e[i].clear(),vis[i]=0;
		gg=0;int cnt=0;
		rep(i,2,m-1)if(s[i]!='?'){
			int u=bh[0][i],v=bh[1][i];
			e[u].pb(Pii(v,s[i]=='1'));e[v].pb(Pii(u,s[i]=='1'));
		}
		for(int j=2;j<n-j+1;j++){
			int u=bh[0][j],v=bh[0][n-j+1];//if(m==1)printf("e %d %d\n",u,v);
			e[u].pb(Pii(v,0));e[v].pb(Pii(u,0));
		}
		for(int j=2;j<m-j+1;j++){
			int u=bh[1][j],v=bh[1][m-j+1];
			e[u].pb(Pii(v,0));e[v].pb(Pii(u,0));
		}
		static int dot[N],q[N];int len=0;
		rep(i,max(m,2),n-1)if(s[i]!='?'){
		//	if(col[bh[0][i]]!=-1&&col[bh[0][i]]!=((s[i]=='1')^(i==m)))gg=1;
		//	col[bh[0][i]]=(s[i]=='1')^(i==m);
			dot[++len]=bh[0][i];q[len]=(s[i]=='1')^(i==m);
		}
		rep(i,1,len)if(!vis[dot[i]])col[dot[i]]=q[i],dfs(dot[i]);
		rep(i,1,num)if(!vis[i])col[i]=0,dfs(i),cnt++;
		rep(i,1,len)gg|=col[dot[i]]!=q[i];
	//	if(!gg)cerr<<m<<' '<<num<<' '<<cnt<<endl;
		int now=1;rep(i,1,cnt)now=2LL*now%mo;
		if(!gg)res=(res+now)%mo;
	}
	cout<<res;
	return 0;
}