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
int T;
char s[N];
int a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		scanf("%s",s+1);
		rep(i,n)a[i]=s[i]-'0';
		scanf("%s",s+1);
		rep(i,n)b[i]=s[i]-'0';
		int u1=0,v1=0,u0=0,v0=0;
		rep(i,n){
			if(a[i]!=b[i]){
				if(a[i])v0++;
				else u0++;
			}
		}
		rep(i,n){
			if(a[i]==b[i]){
				if(a[i])v1++;
				else u1++;
			}
		}
		if(u0==v0){
			if(u1+1==v1)printf("%d\n",min(v0+u0,v1+u1));
			else printf("%d\n",v0+u0);
		}
		else{
			if(u1+1==v1)printf("%d\n",v1+u1);
			else puts("-1");
		}
	}
	return 0;
}