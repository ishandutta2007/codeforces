#include<bits/stdc++.h>
//#define fi first
//#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
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
int ch[1100000][10],dep[1100000],fa[1100000][20],lst[1100000],tot;
struct Pii{
	int fi,se;Pii(int x=0,int y=0){fi=x;se=y;}
bool operator <(const Pii &y)const{//[x<y]
	int u=fi,v=y.fi;
	if(v<0)return 1;
	if(u<0)return 0;
	if(dep[u]!=dep[v])return dep[u]<dep[v];
	per(i,19,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return lst[u]<lst[v];
}
bool operator >(const Pii &x)const{//[y>x]
	int u=x.fi,v=fi;
	if(v<0)return 1;
	if(u<0)return 0;
	if(dep[u]!=dep[v])return dep[u]<dep[v];
	per(i,19,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return lst[u]<lst[v];
}
};
const int N = 1100000,mo=1e9+7;
int n,m,A[N],B[N];vector<Pii> e[N];
bool vis[N];int dis[N],ans[N];
priority_queue<Pii,vector<Pii>,greater<Pii> >heap;
//inline int kthfa(int u, int k){for(int i=0;(1<<i)<=k;i++)if(k>>i&1)u=fa[u][i];return u;}

Vi getarr(int x){
	Vi r;while(x)r.pb(x%10),x/=10;reverse(r.begin(),r.end());
	return r;
}
int main() {
	read(n);read(m);
	rep(i,1,m){
		read(A[i]);read(B[i]);
		e[A[i]].pb(Pii(B[i],i));
		e[B[i]].pb(Pii(A[i],i));
	}
	memset(dis,-1,sizeof(dis));dis[1]=0;
	heap.push(Pii(dis[1],1));
	while(!heap.empty()){
		Pii tmp=heap.top();heap.pop();int u=tmp.se;
		if(tmp.fi!=dis[u])continue;vis[u]=1;
		rep(i,0,SZ(e[u])-1)if(!vis[e[u][i].fi]){
			Vi num=getarr(e[u][i].se);int cur=dis[u];
			rep(j,0,SZ(num)-1){
				if(!ch[cur][num[j]]){
				//	cerr<<"edge "<<cur<<' '<<num[j]<<' '<<tot+1<<endl;
					ch[cur][num[j]]=++tot,dep[ch[cur][num[j]]]=dep[cur]+1;lst[ch[cur][num[j]]]=num[j];
					fa[ch[cur][num[j]]][0]=cur;int v=ch[cur][num[j]];
					for(int k=1;k<=19;k++)fa[v][k]=fa[fa[v][k-1]][k-1];
				}
				cur=ch[cur][num[j]];
			}
			if(cur!=dis[e[u][i].fi]&&Pii(cur,e[u][i].fi)<Pii(dis[e[u][i].fi],e[u][i].fi)){
				/*cerr<<ans[e[u][i].fi]<<' ';
				if(ans[e[u][i].fi]==114){
					cerr<<"GG "<<cur<<' '<<dis[e[u][i].fi]<<endl;
					int x=cur,y=dis[e[u][i].fi];
					cerr<<"GG "<<dep[x]<<' '<<dep[y]<<endl;
					per(i,19,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
					cerr<<"GG "<<x<<' '<<y<<endl;
					cerr<<"GG "<<lst[x]<<' '<<lst[y]<<endl;
				}*/
				dis[e[u][i].fi]=cur;heap.push(Pii(dis[e[u][i].fi],e[u][i].fi));
				ans[e[u][i].fi]=ans[u];
				/*if(e[u][i].fi==11){
					rep(j,0,SZ(num)-1)cerr<<num[j]<<' ';cerr<<endl;
				}*/
				rep(j,0,SZ(num)-1)ans[e[u][i].fi]=(10LL*ans[e[u][i].fi]+num[j])%mo;
			//	cerr<<ans[e[u][i].fi]<<endl;
			}
		}
	}
	rep(i,2,n)printf("%d\n",ans[i]);
	return 0;
}