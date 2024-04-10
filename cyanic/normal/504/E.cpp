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
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
const int N=300005,M=19,mod=1e9+7,seed=19260817;
int d[N],fa[20][N],x[20][N],y[20][N],lg[N],pw[20];
int sz[N],sn[N],id[N],cur[N],anc[N],clk;
int n,Q,a,b,u,v;
char str[N];
vi e[N];
 
void init(int n){
	lg[0]=-1;
	rep(i,1,n)lg[i]=lg[i>>1]+1;
	pw[0]=seed;
	rep(i,1,M)pw[i]=(ll)pw[i-1]*pw[i-1]%mod;
}
 
int lca(int a,int b){
	int x=anc[a],y=anc[b];
	while(x!=y)
		if(d[x]>d[y])a=fa[0][x],x=anc[a];
		else b=fa[0][y],y=anc[b];
	return d[a]<d[b]?a:b;
}
 
int Kth(int a,int k){
	int aim=d[a]-k;
	while(d[anc[a]]>aim)a=fa[0][anc[a]];
	return cur[id[a]-(d[a]-aim)];
}
 
void dfs(int u){
	x[0][u]=y[0][u]=str[u];
	rep(i,1,M){
		int f=fa[i-1][u];
		fa[i][u]=fa[i-1][f];
		x[i][u]=(x[i-1][u]+(ll)x[i-1][f]*pw[i-1])%mod;
		y[i][u]=((ll)y[i-1][u]*pw[i-1]+y[i-1][f])%mod;
	}
	sz[u]=1;
	for(auto v:e[u])if(v!=fa[0][u]){
		fa[0][v]=u,d[v]=d[u]+1;
		dfs(v),sz[u]+=sz[v];
		if(sz[v]>sz[sn[u]])sn[u]=v;
	}
}
 
void dfs2(int u,int top){
	anc[cur[id[u]=++clk]=u]=top;
	if(sn[u])dfs2(sn[u],top);
	for(auto v:e[u])
		if(v!=fa[0][u]&&v!=sn[u])
			dfs2(v,v);
}
 
int aa(int a,int b,int u,int v,int &ans){
	int len=min(d[a]-d[b],d[u]-d[v])+1;
	if(!a||!b||!u||!v||len<=0||str[a]!=str[u])return 0;
	int res=0;
	per(i,lg[len],0)
		if(res+(1<<i)<=len&&x[i][a]==x[i][u])
			a=fa[i][a],u=fa[i][u],res+=1<<i;
	return ans+=res,res==len;
}
 
int ba(int a,int b,int u,int v,int &ans){
	int len=min(d[b]-d[a],d[u]-d[v])+1;
	if(!a||!b||!u||!v||len<=0||str[a]!=str[u])return 0;
	if(d[b]-d[a]>d[u]-d[v])b=Kth(b,d[b]-d[a]+1-len);
	static int A[30]; int res=0; A[0]=b;
	rep(i,0,lg[len])A[i+1]=(len>>i&1?fa[i][A[i]]:A[i]);
	per(i,lg[len],0)if(len>>i&1)
		if(x[i][u]!=y[i][A[i]]){
			b=A[i],res+=1<<i,res--;
			per(j,i-1,0)
				if(y[j][fa[j][b]]!=x[j][u])
					b=fa[j][b],res-=1<<j;
				else u=fa[j][u];
			return ans+=res,0;
		}
		else res+=1<<i,u=fa[i][u];
	return ans+=len,1;
}
 
int bb(int a,int b,int u,int v,int &ans){
	int len=min(d[b]-d[a],d[v]-d[u])+1;
	if(!a||!b||!u||!v||len<=0||str[a]!=str[u])return 0;
	if(d[b]-d[a]>d[v]-d[u])swap(a,u),swap(b,v);
	v=Kth(v,d[v]-d[u]+1-len);
	static int A[30],B[30]; int res=0;
	A[0]=b,B[0]=v;
	rep(i,0,lg[len]){
		A[i+1]=(len>>i&1?fa[i][A[i]]:A[i]);
		B[i+1]=(len>>i&1?fa[i][B[i]]:B[i]);
	}
	per(i,lg[len],0)if(len>>i&1)
		if(y[i][A[i]]!=y[i][B[i]]){
			b=A[i],v=B[i],res+=1<<i,res--;
			per(j,i-1,0)
				if(y[j][fa[j][b]]!=y[j][fa[j][v]])
					b=fa[j][b],v=fa[j][v],res-=1<<j;
			return ans+=res,0;
		}
		else res+=1<<i;
	return ans+=len,1;
}
 
int main(){
	read(n);
	scanf("%s",str+1);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	init(n);
	d[1]=1,dfs(1),dfs2(1,1);
	read(Q);
	rep(T,1,Q){
		int x,y,ans=0;
		read(a),read(b);
		read(u),read(v);
		x=lca(a,b),y=lca(u,v);
		if(d[a]-d[x]>d[u]-d[y])
			swap(a,u),swap(b,v),swap(x,y);
		if(aa(a,x,u,y,ans)){
			u=Kth(u,d[a]-d[x]),a=x;
			if(u!=v&&a!=b){
				if(u==y)ans--,bb(a,b,u,v,ans);
				else{
					a=Kth(b,d[b]-d[a]-1),u=fa[0][u];
					if(ba(a,b,u,y,ans)&&d[b]-d[a]>d[u]-d[y]){
						a=Kth(b,d[b]-d[a]-(d[u]-d[y])),u=y;
						ans--,bb(a,b,u,v,ans);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}