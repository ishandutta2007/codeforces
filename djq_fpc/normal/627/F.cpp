#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,a[200005],b[200005],c[200005],d[200005],pa[200005],pb[200005],vis[200005],fa[200005],dep[200005],dfn[200005],ti,p,p1,p2,f[200005],tp;
bool incir[200005];
vector<int> bi[200005],nd[200005],ed;
long long ans,c1,c2;
vector<int> cir,tmp,all;
int lca(int p1,int p2)
{
	while(dep[p1]>dep[p2]){p1=fa[p1];}
	while(dep[p2]>dep[p1]){p2=fa[p2];}
	while(p1!=p2){p1=fa[p1];p2=fa[p2];}
	return p1;
}
void dfs1(int x,int p)
{
	fa[x]=p;dfn[x]=++ti;
	ff(bi[x],it){
		if(*it==p) continue;
		dep[*it]=dep[x]+1;dfs1(*it,x);
	}
}
void dfs2(int x,int p)
{
	f[x]=vis[x];
	ff(bi[x],it){
		if(*it==p) continue;
		dfs2(*it,x);f[x]|=f[*it];
		if(f[*it]) nd[x].push_back(*it); 
	}
}
void dfs3(int x)
{
	if(nd[x].empty()) ed.push_back(x);
	ff(nd[x],it) dfs3(*it);
}
void dfs4(int x,int p)
{
	fa[x]=p;
	ff(bi[x],it){
		if(*it==p||incir[*it]) continue;
		dfs4(*it,x);
	}
}

long long solve()
{
	long long ans=0;
	int i,j;
	fz0k(i,m){
		if(a[i]==0) break;
	}
	fz0k(j,m){
		if(b[j]==0) break;
	}
	while(i!=j){
		ans++;
		swap(a[i],a[(i+1)%m]);
		i++;i%=m;
	}
	
	int c1=0,c2=0;
	fz0k(i,m){
		if(a[i]) pa[a[i]]=++c1;
		if(b[i]) pb[b[i]]=++c2;
	}
	int t=pa[1]-pb[1];if(t<0) t+=m-1;
	fz(i,2,m-1){
		int tt=pa[i]-pb[i];if(tt<0) tt+=m-1;
		if(t!=tt){
			puts("-1");
			exit(0);
		}
	}
	ans+=1ll*t*m;
	return ans;
}

int main()
{
	scanf("%d",&n);
	fz1(i,n) scanf("%d",&a[i]);
	fz1(i,n) scanf("%d",&b[i]);
	fz1(i,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs1(1,0);
	
	fz1(i,n) c[i]=a[i];
	fz1(i,n) d[i]=b[i]; 
	fz1(i,n) if(a[i]==0){
		p=i;break;
	}
	while(p!=1){
		swap(c[p],c[fa[p]]);
		p=fa[p];
	}
	fz1(i,n) if(b[i]==0){
		p=i;break;
	}
	while(p!=1){
		swap(d[p],d[fa[p]]);
		p=fa[p];
	}
	bool s0=1;int mi=0,mx=0;
	fz1(i,n){
		if(c[i]!=d[i]){
			vis[i]=1;
			s0=0;
			if(!mi||dfn[i]<dfn[mi]) mi=i;
			if(!mx||dfn[i]>dfn[mx]) mx=i;
		}
	}
	if(s0){
		printf("0 ");
		fz1(i,n) if(a[i]==0){
			p1=i;break;
		}
		fz1(i,n) if(b[i]==0){
			p2=i;break;
		}
		while(dep[p1]>dep[p2]){p1=fa[p1];ans++;}
		while(dep[p2]>dep[p1]){p2=fa[p2];ans++;}
		while(p1!=p2){p1=fa[p1];p2=fa[p2];ans+=2;}
		printf("%lld\n",ans);
		return 0;
	}
	
	tp=lca(mi,mx);
	if(tp==mi) tp=fa[tp];
	dfs2(tp,fa[tp]);
	if(nd[tp].size()>2){
		puts("-1");
		return 0;
	}
	fz1(i,n) if(i!=tp&&nd[i].size()>1){
		puts("-1");
		return 0;
	}
	
	dfs3(tp);
	if(nd[tp].size()==1) nd[tp].push_back(tp);
	p1=nd[tp][0];
	while(!nd[p1].empty()) p1=nd[p1][0];
	while(p1!=tp){
		cir.push_back(p1);
		p1=fa[p1];
	}
	cir.push_back(tp);
	p2=nd[tp][1];
	while(p2!=tp&&!nd[p2].empty()) p2=nd[p2][0];
	while(p2!=tp){
		tmp.push_back(p2);
		p2=fa[p2];
	}
	while(!tmp.empty()){
		cir.push_back(tmp.back());
		tmp.pop_back();
	}
	
	m=cir.size();
	fz1(i,n) if(a[i]==0){
		p1=i;break;
	}
	fz1(i,n) if(b[i]==0){
		p2=i;break;
	}
	ff(cir,it){
		incir[*it]=1;
	}
	ff(cir,it) dfs4(*it,0);
	while(!incir[p1]){
		swap(a[p1],a[fa[p1]]);
		p1=fa[p1];ans++;
	}
	while(!incir[p2]){
		swap(b[p2],b[fa[p2]]);
		p2=fa[p2];ans++;
	}
	
	fz0k(i,m){
		c[i]=a[cir[i]];
		d[i]=b[cir[i]];
	}
	all.clear();
	fz0k(i,m) all.push_back(c[i]);
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	fz0k(i,m){
		a[i]=c[i]=lower_bound(all.begin(),all.end(),c[i])-all.begin();
	}
	all.clear();
	fz0k(i,m) all.push_back(d[i]);
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	fz0k(i,m){
		b[i]=d[i]=lower_bound(all.begin(),all.end(),d[i])-all.begin();
	}
	
	c1=solve();
	reverse(c,c+m);
	reverse(d,d+m);
	fz0k(i,m){
		a[i]=c[i];
		b[i]=d[i];
	}
	c2=solve();
	
	p1=nd[tp][0];
	while(!nd[p1].empty()) p1=nd[p1][0];
	p2=nd[tp][1];
	while(p2!=tp&&!nd[p2].empty()) p2=nd[p2][0];
//	if(n==200000) printf("%d %lld %lld %lld\n",m,ans,c1,c2);
	printf("%d %d %lld\n",min(p1,p2),max(p1,p2),ans+min(c1,c2));
	return 0;
}