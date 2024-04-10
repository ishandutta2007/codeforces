#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 1e6+11,inf=1e8;
int n,a[N],pr[N],len,mrk[N],res=inf,d[1005][1005];Vi b[N],e[N];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])pr[++len]=i;
		rep(j,1,len){
			if(i*pr[j]>n)break;
			mrk[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
}
int main() {getp(1e6);
	rep(i,0,1000)rep(j,0,1000)d[i][j]=inf;
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n){
		int x=1;
		while(mrk[a[i]]){
			int y=mrk[a[i]],c=0;
			while(a[i]%y==0)a[i]/=y,c++;
			if(c&1)x*=y;
		}
		if(a[i]>1)x*=a[i];
		a[i]=x;if(x==1){puts("1");exit(0);}
	}
	sort(a+1,a+n+1);Vi dot;
	rep(i,1,n-1)if(a[i]==a[i+1]){puts("2");exit(0);}
	rep(i,1,n)if(!mrk[a[i]])b[a[i]].pb(1),dot.pb(a[i]);else{
		int x=mrk[a[i]],y=a[i]/x;
		e[x].pb(y);e[y].pb(x);dot.pb(x);dot.pb(y);
	}
	sort(ALL(dot));dot.erase(unique(ALL(dot)),dot.end());
	static int q[N],dis[N],fa[N],bel[N];
//	rep(i,1,1000)if(SZ(b[i])>=2)umin(res,b[i][0]+b[i][1]);
	rep(rt,2,1000)if(!mrk[rt]){
		int f=0,r=1;q[f]=rt;
		for(int i:dot)dis[i]=inf,fa[i]=0;dis[rt]=0;
		while(f!=r){
			int u=q[f++];
			for(int i:e[u])if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;q[r++]=i;fa[i]=u;
			}
		}
		for(int i:dot)if(i!=rt&&!mrk[i]&&dis[i]<inf){
			for(int j:e[i])if(i!=fa[j]&&j!=fa[i]&&j!=rt&&j!=i)umin(res,dis[i]+dis[j]+1);
			/*if(SZ(b[rt])&&SZ(b[i]))umin(res,b[rt][0]+b[i][0]+dis[i]);
			rep(j,1,1000)if(d[i][j]<inf&&i!=fa[j]&&j!=fa[i]&&j!=rt&&j!=i){
				umin(res,dis[i]+dis[j]+d[i][j]);
			//	if(dis[i]+dis[j]+d[i][j]==2)printf("qaq %d %d %d\n",rt,i,j);
			}*/
		}
	}
	rep(i,1,1e6)dis[i]=inf;int f=0,r=0;
	rep(i,1,1e6)if(SZ(b[i]))q[r++]=i,dis[i]=0,bel[i]=i;
	while(f!=r){
		int u=q[f++];
		for(int v:e[u])if(dis[v]>dis[u]+1){
			dis[v]=dis[u]+1;
			q[r++]=v;bel[v]=bel[u];
		}
	}
	rep(u,1,1e6)for(int v:e[u])if(bel[u]!=bel[v])umin(res,dis[u]+dis[v]+3);
	printf("%d",res<inf?res:-1);
	return 0;
}