#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
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
const int N = 666666;
int n,a[N],s[N],len,q[N],F=1,R=1;Vi tmp;
int query(){
	int u=0;printf("? %d\n",SZ(tmp));
	rep(i,0,SZ(tmp)-1)printf("%d ",tmp[i]);puts("");
	fflush(stdout);
	read(u);
	tmp.clear();
	return u;
}
Vi nxt,e[N],res;int g[2505];
void solve(int k, int u, int l, int r){
	if(l>r)return;
	if(k%2&&k/2>=1)g[k]=g[k>>1]-g[k-1];
	else {
		int a,b;rep(i,l,r)tmp.pb(s[i]);a=query();
		rep(i,l,r)tmp.pb(s[i]);tmp.pb(u);b=query();g[k]=b-a;
	}
	if(!g[k])return;
	if(l==r){nxt.pb(s[l]);return;}
	int mid=(l+r)>>1;solve(k<<1,u,l,mid);solve(k<<1|1,u,mid+1,r);
}
int pre[N];
void bfs(int S, int T){
	memset(pre,-1,sizeof(pre));
	int f=1,r=1;q[r++]=S;pre[S]=0;
	while(f!=r){
		int u=q[f++];//printf("bfs %d\n",u);
		per(i,SZ(e[u])-1,0)if(pre[e[u][i]]==-1){//WA
			pre[e[u][i]]=u;q[r++]=e[u][i];
		}
	}
	int cnt=0;
	for(int u=T;u;u=pre[u]){res.pb(u);cnt++;assert(cnt<=n);}
}
int main() {
	read(n);rep(i,1,n)a[i]=-1;q[R++]=1;a[1]=0;
	while(F!=R){
		int u=q[F++];len=0;rep(i,1,n)if(a[i]==-1)s[++len]=i;
		nxt.clear();memset(g,-1,sizeof(g));solve(1,u,1,len);
		rep(i,0,SZ(nxt)-1)a[nxt[i]]=a[u]^1,e[u].pb(nxt[i]),e[nxt[i]].pb(u),q[R++]=nxt[i];nxt.clear();
		len=0;rep(i,1,n)if(a[i]==a[u]&&u!=i)s[++len]=i;
		memset(g,-1,sizeof(g));solve(1,u,1,len);
		if(SZ(nxt)){
			bfs(u,nxt[0]);printf("N %d\n",SZ(res));
			rep(i,0,SZ(res)-1)printf("%d ",res[i]);fflush(stdout);
			return 0;
		}
		if(F==R)rep(i,1,n)if(a[i]==-1){q[R++]=i;a[i]=0;break;}//multiple components!
	}
	rep(i,1,n)if(a[i]==1)tmp.pb(i);
	printf("Y %d\n",SZ(tmp));rep(i,0,SZ(tmp)-1)printf("%d ",tmp[i]);fflush(stdout);
	return 0;
}