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
int T,n,cnt;
int x[N],w[N],v[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&x[i]);
		cnt=0;
		w[0]=-1;
		rep(i,n){
			if(x[i]!=w[cnt]){
				w[++cnt]=x[i];
				v[cnt]=0;
			}
			v[cnt]++;
		}
		int ans=cnt,i=1;
		while(i<=cnt&&v[i]==1)i++;
		while(i<=cnt){
			int nw=i+1;
			while(nw<=cnt&&v[nw]==1)nw++;
			if(nw>cnt){
				ans++;
				break;
			}
			if(nw-i!=w[nw]-w[i])ans++;
			i=nw;
		}
		printf("%d\n",ans);
	}
	return 0;
}