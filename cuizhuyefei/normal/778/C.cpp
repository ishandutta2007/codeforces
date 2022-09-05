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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 306000;
int n,ch[N][26],dep[N],sz[N],son[N],ans1=1e9,ans2,rt;Vi dot[N];
vector<Pii>rec;
void dfs(int u, int d){
	dep[u]=d;sz[u]=1;rep(i,0,25)if(ch[u][i]){
		dfs(ch[u][i],d+1),sz[u]+=sz[ch[u][i]];
		if(sz[ch[u][i]]>sz[son[u]])son[u]=ch[u][i];
	}
}
inline int merge(int x, int y){
	int res=1;
	rep(i,0,25)if(ch[y][i]){
		if(!ch[x][i])ch[x][i]=ch[y][i],rec.pb(Pii(x,i));
		else res+=merge(ch[x][i],ch[y][i]);
	}
	return res;
}
inline int calc(int x){
	int res=0;
	rep(i,0,25)if(ch[x][i]){
		if(!ch[rt][i])ch[rt][i]=ch[x][i];
		else res+=merge(ch[rt][i],ch[x][i]);
	}
	return res;
}
inline int solve(int x){
	int res=0;rep(i,0,25)res+=ch[x][i]>0;
	if(son[x]){
		memset(ch[rt],0,sizeof(ch[rt]));res+=calc(son[x]);
		rep(i,0,25)if(ch[x][i]&&ch[x][i]!=son[x])res+=calc(ch[x][i]);
		rep(i,0,SZ(rec)-1)ch[rec[i].fi][rec[i].se]=0;rec.clear();
	}
	return res;
}
int main() {
	read(n);rt=n+1;rep(i,1,n-1){
		int u,v;read(u);read(v);char t[4];scanf("%s",t);
		ch[u][t[0]-'a']=v;
	}
	dfs(1,0);rep(i,1,n)dot[dep[i]].pb(i);
	rep(i,0,n)if(SZ(dot[i])){
		int now=n;rep(j,0,SZ(dot[i])-1)now-=solve(dot[i][j]);
		if(now<ans1)ans1=now,ans2=i+1;
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}