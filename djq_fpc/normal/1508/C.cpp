#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
long long ans;
int n,m,i,j,px[200005],py[200005],pz[200005],xorsum,ax[200005],ay[200005],ca;
int dep[200005],pa[200005][19],c[200005];
set<int> s;
set<int> bis[200005];
vector<pair<int,int> > bi[200005];
void bfs(int x)
{
	queue<int> qx;
	qx.push(x);s.erase(x);
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		vector<int> del;
		ff(s,it){
			if(!bis[x].count(*it)){
				del.push_back(*it);
			}
		}
		ff(del,it){
			s.erase(*it);
			qx.push(*it);
			ca++;
			ax[ca]=x;ay[ca]=*it;
		}
	}
}
struct ii
{
	int x,y,z;
}e[400005];
bool cmp(ii x,ii y)
{
	return x.z<y.z;
}
int fa[200005];
int fnd(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
void dfs(int x,int p)
{
	pa[x][0]=p;
	ff(bi[x],it){
		if(it->fi!=p){
			dep[it->fi]=dep[x]+1;
			c[it->fi]=c[x]+it->se;
			dfs(it->fi,x);
		}
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y],i;
	fd0g(i,18)if((t>>i)&1) x=pa[x][i];
	if(x==y) return x;
	fd0g(i,18)if(pa[x][i]!=pa[y][i]){
		x=pa[x][i];y=pa[y][i];
	}
	return pa[x][i];
}
int main()
{
	read(n);read(m);
	fz1(i,m){
		read(px[i]);read(py[i]);read(pz[i]);
		bis[px[i]].insert(py[i]);
		bis[py[i]].insert(px[i]);
		xorsum^=pz[i];
	}
	fz1(i,n) s.insert(i);
	while(!s.empty()){
		bfs(*s.begin());
	}
	fz1(i,m){
		e[i]=(ii){px[i],py[i],pz[i]};
	}
	sort(e+1,e+m+1,cmp);
	fz1(i,n){
		fa[i]=i;
	}
	fz1(i,ca){
		bi[ax[i]].push_back(make_pair(ay[i],1));
		bi[ay[i]].push_back(make_pair(ax[i],1));
		fa[fnd(ax[i])]=fnd(ay[i]);
	}
	fz1(i,m){
		if(fnd(e[i].x)!=fnd(e[i].y)){
			fa[fnd(e[i].x)]=fnd(e[i].y);
			ans+=e[i].z;
			bi[e[i].x].push_back(make_pair(e[i].y,0));
			bi[e[i].y].push_back(make_pair(e[i].x,0));
		}
	}
	if(ca+m<1ll*n*(n-1)/2){
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0);
	fz1(j,18)fz1(i,n) pa[i][j]=pa[pa[i][j-1]][j-1];
	fz1(i,m){
		if(c[px[i]]+c[py[i]]-2*c[lca(px[i],py[i])]>0){
			xorsum=min(xorsum,pz[i]);
		}
	}
	cout<<ans+xorsum<<endl;
	return 0;
}