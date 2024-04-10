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
const int N=5e5+7;
const int mod=1e9+7;
int n,m,cnt=0;
int f[N],a[N];
bool v[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,m)f[i]=i;
	rep(i,n){
		int k; scanf("%d",&k);
		if(k==1){
			int x; scanf("%d",&x);
			int p=ff(x);
			if(!v[p]){
				v[p]=1;
				a[++cnt]=i;
			}
		}
		else{
			int x,y; scanf("%d%d",&x,&y);
			x=ff(x); y=ff(y);
			if(x==y)continue;
			if(v[x]&&v[y])continue;
			f[y]=x;
			v[x]|=v[y];
			a[++cnt]=i;
		}
	}
	int ans=1;
	rep(i,cnt)ans=(ans+ans)%mod;
	printf("%d %d\n",ans,cnt);
	rep(i,cnt)printf("%d ",a[i]);
	puts("");
	return 0;
}