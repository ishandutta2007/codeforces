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
const int N=1e5+7;
const int INF=1e9+7;
int T,n,m;
int f[N],sz1[N],sz2[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,n){
			sz1[i]=1;
			sz2[i]=0;
			f[i]=i;
		}
		rep(i,m){
			int x,y; scanf("%d%d",&x,&y);
			if(ff(x)!=ff(y)){
				sz1[ff(x)]+=sz1[ff(y)];
				sz2[ff(x)]+=sz2[ff(y)];
				f[ff(y)]=ff(x);
			}
			sz2[ff(x)]++;
		}
		int ans=0;
		rep(i,n){
			if(ff(i)!=i)continue;
			if(sz1[i]==1)continue;
			ans+=sz2[i]+(sz2[i]==sz1[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}