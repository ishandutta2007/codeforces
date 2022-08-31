#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef long double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000,M=1000000;
int n,m,f[N][3],q,par[N],fid[N];
VI e[N];
struct p3 {
	db x,y,z;
	p3() {}
	p3(db x,db y,db z):x(x),y(y),z(z) {}
}p[N];

p3 operator - (const p3 &a,const p3 &b) {
	return p3(a.x-b.x,a.y-b.y,a.z-b.z);
}
p3 operator * (const p3 &a,const p3 &b) {
	return p3(a.y*b.z-a.z*b.y,a.z*b.x-b.z*a.x,a.x*b.y-a.y*b.x);
}
db abs(p3 a) {
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
} 
vector<array<db,5>> area[N];
map<PII,VI> pr;
vector<PII> que[M+10],cha[M+10],con[M+10];
db ans[N],coef[N][3];


int find(int x) { return par[x]==x?x:par[x]=find(par[x]); }
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[i]=p3(x,y,z);
	}
	scanf("%d",&m);
	rep(i,0,m) {
		scanf("%d%d%d",&f[i][0],&f[i][1],&f[i][2]);
		rep(j,0,3) fid[f[i][j]]=i;
		//rep(j,0,3) rep(k,0,3) if (j!=k) e[f[i][j]].pb(f[i][k]);
		rep(j,0,3) rep(k,0,3) if (f[i][j]<f[i][k]) {
			int u=f[i][j],v=f[i][k];
			pr[{u,v}].pb(i);
		}
		sort(f[i],f[i]+3,[&](int x,int y) {
			return p[x].z<p[y].z;
		});
		int u=f[i][0],v=f[i][1],w=f[i][2];
		db s=abs((p[v]-p[u])*(p[w]-p[u]));
		area[i].pb({0,p[u].z,0,0,s});
		// h<=p[u].z   s
		// p[u].z<=h<=p[v].z
		if (p[u].z<p[v].z) {
			db l1=abs(p[v]-p[u]),l21=abs(p[w]-p[u]);
			db t1=s/l1/l21;
			db l2=l21/(p[w].z-p[u].z)*(p[v].z-p[u].z);
			db c1=l1*l2*t1/(p[v].z-p[u].z)/(p[v].z-p[u].z);
			db a=-c1,b=2*c1*p[u].z,c=s-c1*p[u].z*p[u].z;
			// s - (c1*(h-p[u].z)*(h-p[u].z))
			area[i].pb({p[u].z,p[v].z,a,b,c});
		}
		if (p[v].z<p[w].z) {
			db l1=abs(p[w]-p[v]),l21=abs(p[w]-p[u]);
			db t1=s/l1/l21;
			db l2=l21/(p[w].z-p[u].z)*(p[w].z-p[v].z);			
			db c1=l1*l2*t1/(p[w].z-p[v].z)/(p[w].z-p[v].z);
			db a=c1,b=-2*c1*p[w].z,c=c1*p[w].z*p[w].z;
			area[i].pb({p[v].z,p[w].z,a,b,c});
		}
		area[i].pb({p[w].z,1e6,0,0,0});
		/*for (auto x:area[i]) {
			printf("%.10f %.10f %.10f %.10f %.10f\n",x[0],x[1],x[2],x[3],x[4]);
			printf("%.10f, %.10f\n",x[0]*x[0]*x[2]+x[0]*x[3]+x[4],x[1]*x[1]*x[2]+x[1]*x[3]+x[4]);
		}
		puts("------");*/
		rep(j,0,SZ(area[i])-1) {
			auto &p=area[i][j];
			cha[(int)p[1]].pb({i,j});
		}
	}
	for (auto x:pr) {
		assert(SZ(x.se)<=2);
		if (SZ(x.se)==1) continue;
		int u=x.se[0],v=x.se[1];
		//printf("con %d %d %d\n",(int)max(p[u].z,p[v].z),u,v);
		con[(int)max(p[x.fi.fi].z,p[x.fi.se].z)].pb({u,v});
	}
	scanf("%d",&q);
	rep(i,0,q) {
		int ht,id;
		scanf("%d%d",&ht,&id);
		if (p[id].z<=ht) {
			ans[i]=-1;
			continue;
		}
		que[ht].pb({id,i});
	}
	rep(i,0,m) par[i]=i;
	per(h,0,M+1) {
		for (auto pr:cha[h]) {
			int u=find(pr.fi),v=pr.fi,z=pr.se;
			rep(j,0,3) {
				coef[u][j]-=area[v][z+1][j+2];
				coef[u][j]+=area[v][z][j+2];
			}
		}
		for (auto pr:que[h]) {
			int u=find(fid[pr.fi]);
			ans[pr.se]=coef[u][0]*h*h+coef[u][1]*h+coef[u][2];
		}
		for (auto pr:con[h]) {
			int u=find(pr.fi),v=find(pr.se);
			if (u==v) continue;
			par[u]=v;
			rep(j,0,3) coef[v][j]+=coef[u][j],coef[u][j]=0;
		}
	}
	rep(i,0,q) if (ans[i]<0) puts("-1"); else printf("%.15Lf\n",ans[i]*0.5);
}