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
int T,n;
char s[N];
int a[N],b[N],g[22][22],f[22];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		rep(i,n)a[i]=s[i]-'a';
		scanf("%s",s+1);
		rep(i,n)b[i]=s[i]-'a';
		bool fl=0;
		rep(i,n)if(b[i]<a[i]){fl=1; break;}
		if(fl){
			puts("-1");
			continue;
		}
		memset(g,0,sizeof(g));
		rep(i,n)if(b[i]>a[i])g[a[i]][b[i]]=1;
		int ans=0;
		rep0(i,20)f[i]=i;
		rep0(i,20){
			rep0(j,20){
				if(g[i][j]){
					int x=ff(i),y=ff(j);
					if(x!=y)f[x]=y;
				}
			}
		}
		rep0(i,20)if(ff(i)!=i)ans++;
		printf("%d\n",ans);
	}
	return 0;
}