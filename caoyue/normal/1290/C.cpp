#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=6e5+7;
const ll INF=1e9+7;
ll n,k,num=0,cnt,ans=0;
vector<int>p[N];
ll f[N],sz[N][2],t[N],pos[N],szs[N];
char s[N];
ll ff(ll x){return (f[x]==x)?x:f[x]=ff(f[x]);}
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll v){
	t[x]=v;
	repG(i,x){
		if(t[e[i].v]>=0)continue;
		dfs(e[i].v,v^1);
	}
}
void mer(ll x,ll y){
	if(x!=y){
		ans-=min(sz[x][0],sz[x][1]);
		ans-=min(sz[y][0],sz[y][1]);
		sz[x][0]+=sz[y][0];
		sz[x][1]+=sz[y][1];
		f[y]=x;
		ans+=min(sz[x][0],sz[x][1]);
	}
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	scanf("%s",s+1);
	rep(i,k){
		ll c,x; scanf("%I64d",&c);
		rep(j,c){
			scanf("%I64d",&x);
			p[x].push_back(i);
		}
	}
	cnt=k;
	memset(pos,-1,sizeof(pos));
	rep(i,n){
		if(p[i].size()==2){
			if(s[i]=='0'){
				add(p[i][0],p[i][1]);
				add(p[i][1],p[i][0]);
			}
			else{
				cnt++;
				add(p[i][0],cnt);
				add(p[i][1],cnt);
				add(cnt,p[i][0]);
				add(cnt,p[i][1]);
				p[i].push_back(cnt);
			}
		}
		else if(p[i].size()==1){
			if(s[i]=='1'){
				cnt++;
				add(p[i][0],cnt);
				add(cnt,p[i][0]);
				p[i].push_back(cnt);
				szs[cnt]=-INF;
			}
			else{
				cnt++;
				add(p[i][0],cnt);
				add(cnt,p[i][0]);
				p[i].push_back(cnt);
				szs[cnt]=INF;
			}
		}
	}
	memset(t,-1,sizeof(t));
	rep(i,k)if(t[i]<0)dfs(i,0);
	rep(i,cnt)f[i]=i;
	rep(i,k)sz[i][t[i]]=1;
	rep(i,cnt){
		if(szs[i]==INF)sz[i][t[i]]=INF;
		else if(szs[i]==-INF)sz[i][t[i]^1]=INF;
		else if(i<=k)sz[i][t[i]]=1;
	}
	rep(i,n){
		if(p[i].size()==2){
			ll x=ff(p[i][0]),y=ff(p[i][1]);
			mer(x,y);
		}
		if(p[i].size()==3){
			ll x=ff(p[i][0]),y=ff(p[i][1]),z=ff(p[i][2]);
			mer(x,y);
			mer(y,z);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}