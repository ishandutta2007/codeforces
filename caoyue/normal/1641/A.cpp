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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
int T,n,x;
int a[N];
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		rep(i,n)scanf("%d",&a[i]);
		mp.clear();
		rep(i,n){
			if(!mp.count(a[i]))mp[a[i]]=0;
			mp[a[i]]++;
		}
		int ans=0;
		for(map<int,int>::iterator o=mp.begin();o!=mp.end();o++){
			int t=o->first,v=o->second;
			if(t%x!=0)continue;
			if(!mp.count(t/x))continue;
			int u=min(mp[t/x],v);
			ans+=u;
			mp[t]-=u;
		}
		printf("%d\n",n-ans-ans);
	}
	return 0;
}