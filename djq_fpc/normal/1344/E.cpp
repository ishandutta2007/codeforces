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
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,fa[100005],lc[100005],rc[100005],lst[100005],tag[100005],cnt,pos;
vector<pair<int,int> > bi[100005];
long long dis[100005],cur;
vector<pair<long long,long long> > val;
priority_queue<long long,vector<long long>,greater<long long> > pq;
priority_queue<long long> pq2;
void dfs(int x)
{
	ff(bi[x],it){
		dis[it->first]=dis[x]+it->second;
		dfs(it->first);
	}
}
void upd(int x,int y)
{
	lst[x]=tag[x]=y;
}
void pushdo(int x)
{
	if(tag[x]){
		if(lc[x]) upd(lc[x],tag[x]);
		if(rc[x]) upd(rc[x],tag[x]);
		tag[x]=0;
	}
}
bool isrt(int x)
{
	return (lc[fa[x]]!=x&&rc[fa[x]]!=x);
}
void pushall(int x)
{
	if(!isrt(x)) pushall(fa[x]);
	pushdo(x); 
}
void rot(int x)
{
	int y=fa[x],z=fa[y];
	if(!isrt(y)){
		if(lc[z]==y)lc[z]=x;else rc[z]=x;
	}
	fa[x]=z;fa[y]=x;
	if(lc[y]==x){
		lc[y]=rc[x];if(lc[y]) fa[lc[y]]=y;
		rc[x]=y;
	}
	else{
		rc[y]=lc[x];if(rc[y]) fa[rc[y]]=y;
		lc[x]=y;
	}
}
void splay(int x)
{
	pushall(x);
	while(!isrt(x)){
		int y=fa[x];
		if(!isrt(y)){
			int z=fa[y];
			if((lc[z]==y)==(lc[y]==x))rot(y);else rot(x);
		}
		rot(x);
	}
}
void access(int x,long long t)
{
	splay(x);int y=rc[x],mem=x;
	while(x){
		rc[x]=y;
		if(fa[x]){
			splay(fa[x]);
			val.push_back(make_pair((lst[fa[x]]?lst[fa[x]]+dis[fa[x]]+1:1),t+dis[fa[x]]));
//			cerr<<x<<' '<<val.back().first<<' '<<val.back().second<<endl;
		}
		y=x;x=fa[x];
	}
	splay(x=mem);
	upd(lc[x],t);
}
int main()
{
	read(n);read(m);
	fz1(i,n-1){
		int x,y,z;
		read(x);read(y);read(z);
		bi[x].push_back(make_pair(y,z));
		fa[y]=x;rc[x]=y;
	}
	dfs(1);
	fz1(i,m){
		int x,y;
		read(x);read(y);
		access(x,y);
	}
	sort(val.begin(),val.end());
	while(pos<val.size()||!pq.empty()){
		if(pq.empty()) cur=val[pos].first; else cur++;
		while(pos<val.size()&&val[pos].first==cur){
			pq.push(val[pos++].second);
		}
		if(pq.top()<cur){
			while(!pq2.empty()&&pq2.top()>=cur-1){
				cnt--;pq2.pop();
			}
			printf("%lld %d\n",cur-1,cnt);
			return 0;
		}
//		cerr<<pq.top()<<endl;
		pq2.push(pq.top());pq.pop();cnt++;
	}
	printf("-1 %d\n",cnt);
	return 0;
}