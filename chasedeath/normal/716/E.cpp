#include<cstdio>
#include<cctype>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

typedef long long ll;
#define reg register
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
inline int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;
ll P;

void Exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0)x=1,y=0;
	else Exgcd(b,a%b,y,x),y-=a/b*x;
}
ll Mod_Inv(ll a){
	ll x,y;
	Exgcd(a,P,x,y);
	return (x%P+P)%P;
}

int n;
struct Edge{
	int to,nxt,w;
}e[N<<1];
int head[N],ecnt;
void AddEdge(int u,int v,int w){
	e[++ecnt]=(Edge){v,head[u],w};
	head[u]=ecnt;
}
#define erep(u,i) for(int i=head[u];i;i=e[i].nxt)


ll po[N]={1},Inv[N]={1};
int sz[N];


int vis[N];
void GetSize(int u,int f){
	sz[u]=1;
	erep(u,i) {
		int v=e[i].to;
		if(v==f||vis[v]) continue;
		GetSize(v,u);
		sz[u]+=sz[v];
	}
}

map<int,int> M;
ll Ans;
// po[dep]*x+d=0
// x=-d*Inv[dep]
void CalcSub(int u,int f,int d,int dep){
	d%=P;
	ll t=((P-d)*Inv[dep])%P;
	//cout<<"Calc"<<u<<' '<<t<<' '<<M[t]<<endl;
	Ans+=M[t];
	erep(u,i) {
		int v=e[i].to;
		if(v==f||vis[v]) continue;
		CalcSub(v,u,(1ll*d*10+e[i].w)%P,dep+1);
	}
}

void Upd(int u,int f,int k,int d,int dep){
	d%=P;
	//cout<<"Add"<<u<<' '<<d<<' '<<k<<' '<<endl;
	M[d]+=k;
	erep(u,i) {
		int v=e[i].to;
		if(v==f||vis[v]) continue;
		ll t=(d+po[dep]*e[i].w)%P;
		Upd(v,u,k,t,dep+1);
	}
}

void Calc(int u){
	Upd(u,0,1,0,0);
	M[0]--;
	Ans+=M[0];
	M[0]++;
	erep(u,i) {
		int v=e[i].to;
		if(vis[v]) continue;
		Upd(v,u,-1,e[i].w,1);
		CalcSub(v,u,e[i].w,1);
		Upd(v,u,1,e[i].w,1);
	}
	M.clear();
}

int mi=1e9,rt;
void FindRt(int n,int u,int f){
	int ma=0;
	erep(u,i) {
		int v=e[i].to;
		if(vis[v]||v==f) continue;
		FindRt(n,v,u);
		ma=max(ma,sz[v]);
	}
	ma=max(ma,n-sz[u]);
	if(mi>ma) mi=ma,rt=u;
}


void Solve(int u){
	//cout<<"Begin Solve: "<<u<<endl;
	Calc(u); vis[u]=1;
	erep(u,i) {
		int v=e[i].to;
		if(vis[v]) continue;
		GetSize(v,0);
		mi=1e9,FindRt(sz[v],v,0);
		Solve(rt);
	}
}



int main(){
	n=rd(),P=rd();
	rep(i,2,n) {
		int u=rd()+1,v=rd()+1,w=rd();
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	rep(i,1,n) po[i]=po[i-1]*10%P,Inv[i]=Mod_Inv(po[i]);
	mi=1e9,GetSize(1,0),FindRt(n,1,0);
	Solve(rt);
	printf("%lld\n",Ans);
}