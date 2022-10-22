#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> Pii;
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
int cmax(int &a,int b){ return a<b?a=b,1:0; }

const int N=2010,P=998244353;

int n;
int L[N],R[N];
int dp[N][N][4],sz[N],len[N],fa[N];
vector <int> E[N];

int X[N],Y[N];
int F[N][4],G[N][4];
int p1[N][N][4],p2[N][N][4];
void dfs(int u) {
	sort(E[u].begin(),E[u].end(),[&](int x,int y){ return L[x]<L[y]; });
	if(!E[u].size()) {
		sz[u]=0;
		dp[u][0][0]=R[u]-L[u];
		dp[u][0][1]=R[u];
		dp[u][0][2]=-L[u];
		dp[u][0][3]=0;
		return;
	}
	sz[u]=0;
	for(int v:E[u]) dfs(v);
	memset(F,-63,sizeof F);
	for(int v:E[u]) {
		if(v==E[u][0]) {
			rep(i,0,sz[v]) rep(j,0,3) F[i][j]=dp[v][i][j],p1[v][i][j]=i*16+j;
			sz[u]+=sz[v];
			continue;
		}
		rep(i,0,sz[u]) rep(j,0,3) G[i][j]=F[i][j],F[i][j]=-1e9;
		rep(i,sz[u]+1,sz[u]+sz[v]) rep(j,0,3) F[i][j]=-1e9;
		rep(i,0,sz[u]) rep(a,0,3) rep(j,0,sz[v]) rep(b,0,3) if((a>>1)==(b&1)) {
			if(cmax(F[i+j+(b&1)][(a&1)|(b&2)],G[i][a]+dp[v][j][b])) {
				p1[v][i+j+(b&1)][(a&1)|(b&2)]=j*16+a*4+b;
			}
		}
		sz[u]+=sz[v]+1;
	}
	rep(i,0,sz[u]) rep(j,0,3) {
		if(i && cmax(dp[u][i-1][j],F[i][j])) p2[u][i-1][j]=1;
		if(j&1 && cmax(dp[u][i][j-1],F[i][j]-L[u])) p2[u][i][j-1]=2;
		if(j&2 && cmax(dp[u][i][j-2],F[i][j]+R[u])) p2[u][i][j-2]=3;
		if(j&1 && cmax(dp[u][i][j],F[i][j])) p2[u][i][j]=4;
		if(j&2 && cmax(dp[u][i][j],F[i][j])) p2[u][i][j]=5;
	}
}

stack <Pii> stk;
Pii dfs2(int u,int a,int b) {
	if(!E[u].size()) {
		X[u]=L[u],Y[u]=R[u];
		return mp(L[u],R[u]);
	}
	int typ=p2[u][a][b];
	switch(typ) {
		case 0: { break; }
		case 1: { a+=1; break; }
		case 2: { b+=1; break; }
		case 3: { b+=2; break; }
		case 4: { break; }
		case 5: { break; }
	}
	reverse(E[u].begin(),E[u].end());
	int r=0,lst=-1;
	for(int v:E[u]) {
		int t=p1[v][a][b];
		Pii p=dfs2(v,t>>4,t&3);
		if(t&2) {
			if(lst==-1) r=p.second;
			else stk.push(mp(p.second,lst)),lst=-1;
		}
		if(t&1) lst=p.first;
		a-=(t>>4)+(t&1),b=(t>>2)&3;
	}
	switch(typ) {
		case 0:{ break; }
		case 1:{ if(stk.empty()) stk.push(mp(0,0)); assert(!stk.empty()); X[u]=stk.top().first,Y[u]=stk.top().second,stk.pop(); break; }
		case 2:{ X[u]=L[u],Y[u]=lst; break; }
		case 3:{ X[u]=r,Y[u]=R[u]; break; }
		case 4:{ X[u]=L[u],Y[u]=lst,lst=L[u]; break; }
		case 5:{ X[u]=r,Y[u]=R[u],r=R[u]; break; }
	}
	return mp(lst,r);
}

int main(){
	memset(dp,-63,sizeof dp),scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",L+i,R+i),len[i]=R[i]-L[i];
	rep(i,1,n) {
		rep(j,1,n) if(L[j]<L[i] && R[i]<R[j] && (!fa[i] || len[j]<len[fa[i]])) fa[i]=j;
		if(fa[i]) E[fa[i]].pb(i);
	}
	int ans=0;
	rep(i,1,n) if(!fa[i]) {
		dfs(i);
		ans+=dp[i][0][0],dfs2(i,0,0);
	}
	printf("%d\n",ans);
	rep(i,1,n) printf("%d %d\n",X[i],Y[i]);
}