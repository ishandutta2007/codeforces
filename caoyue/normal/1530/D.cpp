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
int T,n;
int a[N],b[N],in[N],is[N],c[N],h[N],h1[N],h2[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)in[i]=is[i]=0;
		int gg=0;
		rep(i,n){
			if(!in[a[i]]){
				in[a[i]]=i;
				is[i]=1;
				b[i]=a[i];
			}
			else{
				is[i]=0;
				c[i]=in[a[i]];
				gg++;
			}
		}
		if(!gg){
			printf("%d\n",n);
			rep(i,n)printf("%d ",a[i]);
			puts("");
			continue;
		}
		if(gg>1){
			printf("%d\n",n-gg);
			rep(i,n)b[i]=a[i];
			int cc=0,c1=0,c2=0;
			rep(i,n){
				if(!in[i]){
					if(!is[i])h[++cc]=i;
					else h1[++c1]=i;
				}
				else if(!is[i])h2[++c2]=i;
			}
			if(cc!=1){
				rep(i,cc)b[h[i]]=h[i%cc+1];
				rep(i,c1)b[h2[i]]=h1[i];
			}
			else{
				b[h[1]]=h1[1];
				rep(i,c1-1)b[h2[i]]=h1[i+1];
				b[h2[c1]]=h[1];
			}
			rep(i,n)printf("%d ",b[i]);
			puts("");
			continue;
		}
		rep(i,n)b[i]=a[i];
		int t1,t2;
		rep(i,n){
			if(!in[i])t1=i;
			if(!is[i])t2=i;
		}
		if(t1!=t2)b[t2]=t1;
		else b[c[t1]]=t1;
		printf("%d\n",n-1);
		rep(i,n)printf("%d ",b[i]);
		puts("");
	}
	return 0;
}