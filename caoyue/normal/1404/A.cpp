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
const int N=3e5+7;
const int INF=1e9+7;
int T;
char s[N];
int w[N],g[N];

int main(){
	scanf("%d",&T);
	while(T--){
		int n,k; scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		rep(i,n){
			if(s[i]=='?')w[i]=2;
			else w[i]=s[i]-'0';
		}
		rep0(i,k)g[i]=-1;
		bool fl=1;
		rep(i,n){
			if(w[i]==2)continue;
			if(g[i%k]<0)g[i%k]=w[i];
			else{
				if(g[i%k]!=w[i]){
					fl=0;
					break;
				}
			}
		}
		if(!fl){
			puts("NO");
			continue;
		}
		int s1=0,s2=0;
		rep0(i,k){
			if(g[i]==1)s1++;
			if(g[i]==0)s2++;
		}
		if(s1+s1>k)puts("NO");
		else if(s2+s2>k)puts("NO");
		else puts("YES");
	}
	return 0;
}