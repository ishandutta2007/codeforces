#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int M=67;
const int INF=1e9+7;
ll sd1=1717171717,sm1=1919191989;
ll sd2=189741897,sm2=19260817;
int prand(){sd1=sd1*sd1%sm1; sd2=sd2*sd2%sm2; return (int)(sd1+sd2+rand());}
int n,m,p,ans=0;
char s[M];
bool is[N][M],h[M];
int f[N],id[M];

int main(){
	srand(1919810);
	scanf("%d%d%d",&n,&m,&p);
	rep(i,n){
		scanf("%s",s+1);
		rep(j,m)is[i][j]=s[j]=='1';
	}
	rep(i,30){
		int t=prand()%n+1,ss=0;
		rep(j,m)if(is[t][j])id[ss++]=j;
		rep0(k,(1<<ss))f[k]=0;
		rep(j,n){
			int w=0;
			rep0(k,ss)if(is[j][id[k]])w+=(1ll<<k);
			f[w]++;
		}
		rep0(k,ss)rep0(j,(1<<ss))if((j>>k)&1)f[j^(1<<k)]+=f[j];
		int mb=0,md=0;
		rep0(j,(1<<ss)){
			if(f[j]*2<n)continue;
			int bc=0;
			rep0(k,ss)if((j>>k)&1)bc++;
			if(bc>mb){
				mb=bc;
				md=j;
			}
		}
		if(mb>ans){
			ans=mb;
			memset(h,0,sizeof(h));
			rep0(k,ss)if((md>>k)&1)h[id[k]]=1;
		}
	}
	rep(i,m)putchar('0'+h[i]);
	puts("");
	return 0;
}