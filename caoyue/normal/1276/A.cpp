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
int n;
char s[N];
int a[N],b[N],g[N],u[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int cnt=0;
		rep(i,n)g[i]=0;
		REP(i,3,n)if(s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o')g[i]=1;
		rep(i,n-2){
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
				int nw=i;
				while(nw>1&&s[nw-1]=='o')nw--;
				g[nw]|=2;
			}
		}
		rep(i,n){
			if(g[i]==3){
				if(s[i+1]!='o')u[++cnt]=i;
				else{
					int nw=i;
					while(s[nw]=='o')nw++;
					u[++cnt]=nw;
					nw=i;
					while(s[nw]=='o')nw--;
					u[++cnt]=nw;
				}
			}
			else{
				if(g[i]==1){
					int nw=i;
					while(s[nw]=='o')nw--;
					u[++cnt]=nw;
				}
				if(g[i]==2){
					int nw=i;
					while(s[nw]=='o')nw++;
					u[++cnt]=nw;
				}
			}
		} 
		printf("%d\n",cnt);
		rep(i,cnt)printf("%d ",u[i]);
		puts("");
	}
	return 0;
}