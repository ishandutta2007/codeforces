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
const int N = 266666;const double inf=1e9,eps=1e-6;
int n,m,fa[N],top[N],dep[N],sz[N],son[N],dfn[N],idfn[N],num;Vi e[N];
double ans=inf,cur;
struct dot{double x,y;dot(double X=0,double Y=0){x=X;y=Y;}};
vector<pair<dot,dot> >mrk[N];
dot a[N],b[N];int len;pair<double,int>ev[N];
bool cmp1(pair<double,int>a, pair<double,int>b){
	return a.fi!=b.fi?a.fi<b.fi:a.se>b.se;
}
inline double gety(int i){return a[i].x==b[i].x?a[i].y:a[i].y+(cur-a[i].x)/(b[i].x-a[i].x)*(b[i].y-a[i].y);}
struct node{
	int u;
	bool operator<(const node&a)const{return gety(u)!=gety(a.u)?gety(u)<gety(a.u):u<a.u;}
};
set<node>Set;
dot operator-(dot a, dot b){return dot(a.x-b.x,a.y-b.y);}
double Cross(dot a, dot b){return a.x*b.y-a.y*b.x;}
bool isin(dot p, dot a, dot b){return p.x>=min(a.x,b.x)-eps&&p.x<=max(a.x,b.x)+eps&&p.y>=min(a.y,b.y)-eps&&p.y<=max(a.y,b.y)+eps;}
double Abs(double x){return x>0?x:-x;}
bool on_line(dot p, dot a, dot b){return Abs(Cross(p-a,b-a))<=eps;}
double getlen(dot a){return sqrt(a.x*a.x+a.y*a.y);}
void print(int i){
	printf("%lf %lf %lf %lf\n",a[i].x,a[i].y,b[i].x,b[i].y);
}
double getans(int i, int j){
//	cerr<<i<<' '<<j<<endl;
	if(i==j)return inf;
	if(getlen(b[i]-a[i])>getlen(b[j]-a[j]))swap(i,j);
	if(getlen(b[i]-a[i])<=eps){
		if(isin(a[i],a[j],b[j])&&on_line(a[i],a[j],b[j]))return a[i].x;return inf;
	}
	dot A=a[i],B=b[i],C=a[j],D=b[j],u=B-A,v=D-C;
	if(Abs(Cross(u,v))<=eps){
	//	cerr<<"qwq "<<(Abs(gety(i)-gety(j))<=eps)<<' '<<cur<<endl;
		if(Abs(gety(i)-gety(j))<=eps&&cur>=A.x-eps&&cur<=B.x+eps&&cur>=C.x-eps&&cur<=D.x+eps){
		//	cerr<<"qwq "<<Abs(gety(i)-gety(j))<<' '<<cur<<endl;
		//	if(Abs(cur-36.013215859)<=eps)print(i),print(j),cout<<i<<' '<<j<<endl;
		//	cerr<<cur<<endl;
			return cur;
		}
		return inf;
	}
	double k=(Cross(D,v)-Cross(A,v))/Cross(u,v);
	dot p(A.x+k*u.x,A.y+k*u.y);
	if(isin(p,A,B)&&isin(p,C,D)&&on_line(p,A,B)&&on_line(p,C,D))return A.x+k*u.x;return inf;
}
void upd(int i){
	set<node>::iterator it=Set.lower_bound((node){i});
	if(it!=Set.end())umin(ans,getans(i,(*it).u));
	if(it!=Set.begin())it--,umin(ans,getans(i,(*it).u));
}
void dfs1(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;sz[u]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa){
		dfs1(e[u][i],u,Dep+1),sz[u]+=sz[e[u][i]];
		if(sz[e[u][i]]>sz[son[u]])son[u]=e[u][i];
	}
}
void dfs2(int u, int Top){
	top[u]=Top;dfn[u]=++num;idfn[num]=u;
	if(son[u])dfs2(son[u],Top);
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa[u]&&e[u][i]!=son[u])
		dfs2(e[u][i],e[u][i]);
}
int getlca(int u, int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int getpath(int u, int v, double t, int xs, double c){
	while(top[u]!=top[v]){
		int x=fa[top[u]];
	//	cerr<<u<<' '<<x<<' '<<dep[u]-dep[x]<<endl;
		mrk[top[u]].pb(make_pair(dot(t,dfn[u]),dot(t+xs*(dep[u]-dep[x])/c,dfn[u]-(dep[u]-dep[x]))));
		t+=xs*(dep[u]-dep[x])/c;u=fa[top[u]];
	}
	return u;
//	if(u!=v)mrk[top[u]].pb(make_pair(dot(t,dfn[u]),dot(t+xs*(dep[u]-dep[v])/c,dfn[u]-(dep[u]-dep[v]))));
}
int main() {
	read(n);read(m);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0,0);dfs2(1,1);
	rep(i,1,m){
		int T,C,u,v;read(T);read(C);read(u);read(v);double t=T,c=C;
		int lca=getlca(u,v);int ori=u;
		v=getpath(v,lca,t+(dep[u]+dep[v]-2*dep[lca])*1.0/c,-1,c);
		u=getpath(u,lca,t,1,c);
		t+=(dep[ori]-dep[u])*1.0/c;
		if(dep[u]>=dep[v])
			mrk[top[u]].pb(make_pair(dot(t,dfn[u]),dot(t+(dep[u]-dep[v])*1.0/c,dfn[v])));
		else mrk[top[u]].pb(make_pair(dot(t,dfn[u]),dot(t+(dep[v]-dep[u])*1.0/c,dfn[v])));
	}
	rep(t,1,n)if(SZ(mrk[t])){
		Set.clear();len=0;rep(i,0,SZ(mrk[t])-1)len++,a[len]=mrk[t][i].fi,b[len]=mrk[t][i].se;
		rep(i,1,len)if(a[i].x>b[i].x)swap(a[i],b[i]);
	//	rep(i,1,len)cerr<<a[i].x<<' '<<a[i].y<<' '<<b[i].x<<' '<<b[i].y<<endl;
	//	cerr<<endl;
		rep(i,1,len)ev[2*i-1]=make_pair(a[i].x,i),ev[2*i]=make_pair(b[i].x,-i);
		sort(ev+1,ev+len*2+1,cmp1);
		rep(i,1,len*2){
			if((cur=ev[i].fi)>=ans)break;
			if(ev[i].se>0){
				set<node>::iterator it=Set.insert((node){ev[i].se}).fi,pre,nxt;pre=it;nxt=it;nxt++;
				if(it!=Set.begin()){pre--;umin(ans,getans((*pre).u,(*it).u));}
				if(nxt!=Set.end()){umin(ans,getans((*nxt).u,(*it).u));}
			}
			else{
				set<node>::iterator it=Set.find((node){-ev[i].se}),it1,it2;it1=it,it2=it;it2++;
				if(it!=Set.begin()&&it2!=Set.end()){it1--;umin(ans,getans((*it1).u,(*it2).u));}
				Set.erase(it);
			//	Set.erase((node){-ev[i].se}),upd(-ev[i].se);
			}
		}
	}
	if(ans<1e8)printf("%.9lf\n",ans);else puts("-1");
	return 0;
}