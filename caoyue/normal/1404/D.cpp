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
#define F fflush(stdout)
const int N=5e5+7;
const int INF=1e9+7;
int n;
int to[N*2],w[N],sq[N*2];
bool vis[N*2];
int cg(int x){if(x>n)return x-n; return x+n;}
int main(){
	scanf("%d",&n);
	if(n%2==0){
		puts("First");
		F;
		rep(i,n)printf("%d ",i);
		rep(i,n)printf("%d ",i);
		puts("");
		F; 
	}
	else{
		puts("Second");
		F;
		memset(w,-1,sizeof(w));
		rep(i,n*2){
			int x; scanf("%d",&x);
			if(w[x]<0)w[x]=i;
			else {
				to[w[x]]=i;
				to[i]=w[x];
			}
		}
		int cnt=0;
		rep(i,n*2){
			if(!vis[i]){
				vis[i]=vis[cg(i)]=1;
				sq[++cnt]=i;
				sq[++cnt]=cg(i);
				for(int j=to[cg(i)];j!=i;j=to[cg(j)]){
					sq[++cnt]=j;
					sq[++cnt]=cg(j);
					vis[j]=vis[cg(j)]=1;
				}
			}
		}
		int sm1=0,sm2=0;
		rep(i,n*2){
			if(i&1)sm1=(sm1+sq[i])%(2*n);
			else sm2=(sm2+sq[i])%(2*n);
		}
		if(sm1%(2*n)==0){
			rep(i,n)printf("%d ",sq[2*i-1]);
			puts("");
		}
		else{
			rep(i,n)printf("%d ",sq[2*i]);
			puts("");
		}
	}
	return 0;
}