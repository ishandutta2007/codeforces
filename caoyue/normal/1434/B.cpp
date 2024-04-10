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
int n;
int tp[N],v[N],id[N],f[N],w[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}

int main(){
	scanf("%d",&n);
	rep(i,2*n){
		char s[5]; scanf("%s",s);
		if(s[0]=='+')tp[i]=1;
		else {
			tp[i]=2;
			int x; scanf("%d",&x);
			id[x]=i;
			v[i]=x;
		}
		f[i]=i;
	}
	rep(i,n){
		int t=ff(id[i]-1);
		if(!t){
			puts("NO");
			return 0;
		}
		if(tp[t]==2){
			puts("NO");
			return 0;
		}
		w[t]=i;
		f[t]=t-1;
		f[id[i]]=id[i]-1;
	}
	puts("YES");
	rep(i,2*n)if(tp[i]==1)printf("%d ",w[i]);
	puts("");
	return 0;
}