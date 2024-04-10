#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll M=3e2+7;
const ll N2=1e4+7;
const ll P=15;
const ll INF=1e13+7;
ll b[P]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll qz[P]={20,14,12,9,9,8,8,8,8,8,8,8,8,8,1};
ll v[N][P],len[N],a[P],di[N],rm[M],pos[N],dis[M][N2];
ll qu[N*5],bb[N*10],fr[N*10];
bool is[N*10];
vector<ll>w[N];
ll tot=0,gg=0,num=0;
map<ll,ll>mp,ps,drm;
void dfs(ll x,ll f,ll res,ll nw,ll g){
	ll pu=0;
	rep0(i,x+1)pu+=a[i]*qz[i];
	mp[pu]=++tot;
	rep0(i,x+1)v[tot][i]=a[i];
	len[tot]=x;
	di[tot]=g;
	if(f<(1ll<<20))rm[++gg]=tot,drm[tot]=gg;
	if(nw<res&&f*b[x]<(1ll<<40)){
		a[x]++;
		dfs(x,f*b[x],res,nw+1,g/(nw+1)*(nw+2));
		a[x]--;
	}
	if(nw&&f*b[x+1]<(1ll<<40)){
		a[x+1]++;
		dfs(x+1,f*b[x+1],nw,1,g*2);
		a[x+1]--;
	}
}
bool cmp(ll xx,ll yy){return xx>yy;}
struct edge{ll v,next;}e[N*15];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void bfs(ll q){
	rep(i,tot*2)dis[q][i]=1e9;
	ll hd=N,ti=N+1;
	qu[N]=rm[q];
	dis[q][rm[q]]=0;
	while(hd!=ti){
		ll t=qu[hd++];
		repG(i,t){
			if(dis[q][e[i].v]>dis[q][t]+1){
				dis[q][e[i].v]=dis[q][t]+1;
				qu[ti++]=e[i].v;
			}
		}
	}
}
int main(){
	for(int i=P-2;~i;i--)qz[i]*=qz[i+1];
	dfs(0,1,35,0,1);
	ll cnt=0;
	memset(pos,-1,sizeof(pos));
	rep(i,tot){
		int q[P];
		rep0(j,len[i]+2){
			if(v[i][j]>0){
				memset(q,0,sizeof(q));
				rep0(k,len[i]+1)q[k]=v[i][k];
				q[j]--;
				sort(q,q+len[i]+2,cmp);
				ll pu=0;
				rep0(k,len[i]+2)pu+=q[k]*qz[k];
				add(i,mp[pu]);
				add(i+tot,mp[pu]+tot);
			}
			memset(q,0,sizeof(q));
			rep0(k,len[i]+1)q[k]=v[i][k];
			q[j]++;
			sort(q,q+len[i]+2,cmp);
			ll pu=0;
			rep0(k,len[i]+2)pu+=q[k]*qz[k];
			add(i,mp[pu]);
			add(i+tot,mp[pu]+tot);
		}
		if(!ps.count(di[i])){
			ps[di[i]]=++cnt;
			w[cnt].push_back(i);
		}
		else{
			int q=ps[di[i]];
			rep0(j,w[q].size()){
				add(i,w[q][j]+tot);
				add(w[q][j],i+tot);
			}
			w[q].push_back(i);
		}
		add(i,i+tot);
	}
	rep(i,gg)bfs(i);
	ll T,er=0; scanf("%I64d",&T);
	REP(i,2,1e6){
		if(!is[i])bb[++er]=i,fr[i]=i;
		rep(j,er){
			if(i*bb[j]>1e6)break;
			is[i*bb[j]]=1;
			fr[i*bb[j]]=bb[j];
			if(i%bb[j]==0)break;
		}
	}
	while(T--){
		ll a,b; scanf("%I64d%I64d",&a,&b);
		ll da=0,lsa=-1,rb=0,lsb=-1;
		ll as[P],bs[P];
		for(int i=a;i>1;i/=fr[i]){
			if(fr[i]==lsa)as[da]++;
			else as[++da]=1;
			lsa=fr[i];
		}
		for(int i=b;i>1;i/=fr[i]){
			if(fr[i]==lsb)bs[rb]++;
			else bs[++rb]=1;
			lsb=fr[i];
		}
		sort(as+1,as+da+1,cmp);
		sort(bs+1,bs+rb+1,cmp);
		ll pa=0,pb=0;
		rep(i,da)pa+=as[i]*qz[i-1];
		rep(i,rb)pb+=bs[i]*qz[i-1];
		printf("%I64d\n",dis[drm[mp[pa]]][mp[pb]+tot]-1);
	}
	return 0;
}