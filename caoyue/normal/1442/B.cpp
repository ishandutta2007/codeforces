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
const int mod=998244353;
int n,k;
int a[N],p[N],b[N],s[N];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)p[a[i]]=i;
		rep(i,n)s[i]=0;
		rep(i,k){
			scanf("%d",&b[i]);
			b[i]=p[b[i]];
			s[b[i]]++;
		}
		s[0]=s[n+1]=1;
		int ans=1;
		rep(i,k){
			if(s[b[i]-1]&&s[b[i]+1]){
				ans=0;
				break;
			}
			if(!s[b[i]-1]&&!s[b[i]+1])ans=(ans+ans)%mod;
			s[b[i]]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}