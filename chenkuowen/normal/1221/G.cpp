#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool gbit(ll sta,int i){ return (sta>>i)&1; }
ll e[45],f[1<<20|5],g[1<<20|5];
int cnt1,cnt2,cnt3,n;
int c[45];
bool dfs(int x,int type){
	if(c[x]!=0){
		if(c[x]!=type) return false;
		else return true;
	}
	c[x]=type;
	bool ret=1;
	for(int i=0;i<n;++i)
		if(gbit(e[x],i)){
			if(!dfs(i,3-type))
				ret=0;
		}
	return ret;
}

ll solve1(){
	int m=n/2;
	for(int sta=0;sta<1<<(n-m);++sta){
		bool flag=1;
		for(int i=0;i<n-m;++i)
			if(!gbit(sta,i)){
				if((sta&(e[i+m]>>m))!=(e[i+m]>>m)){
					flag=0;
					break;
				}
			}
		g[sta]=flag;
	}
	for(int s=1,sx=2;s<1<<(n-m);sx=(s=sx)<<1)
		for(int i=0;i<1<<(n-m);i+=sx)
			for(int j=i;j<i+s;++j)
				g[j]+=g[j+s];
	ll ans=0;
	for(int sta=0;sta<1<<m;++sta){
		int sta1=0; bool flag=1;
		for(int i=0;i<m;++i){
			if(!gbit(sta,i)){
				if((sta&(e[i]&((1<<m)-1)))!=(e[i]&((1<<m)-1))){
					flag=0;
					break;
				}
				sta1|=e[i]>>m;
			}
		}
		if(flag){
			ans+=g[sta1];
		}
	}
	return ans;
}
ll solve2(){
	if(cnt3>0) return 0;
	else return (1ll<<cnt1+cnt2);
}
int main(){
	int m; scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y; scanf("%d%d",&x,&y); --x; --y;
		e[x]|=1ll<<y;
		e[y]|=1ll<<x;
	}
	memset(c,0,sizeof(c));
	for(int i=0;i<n;++i){
		if(c[i]==0) {
			if(e[i]==0) ++cnt1;
			else if(dfs(i,1)) ++cnt2;
			else ++cnt3;
		}
	}
	ll ans=(1ll<<n)-solve1()*2+solve2();
	ans-=max(0ll,(1ll<<cnt2+cnt3)-2)*(1ll<<cnt1);
	printf("%lld\n",ans);
	return 0;
}