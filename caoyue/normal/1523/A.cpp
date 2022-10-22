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
const int N=1e6+7;
const int INF=1e9+7;
int T,n,m,cnt;
char s[N];
int a[N],w[N],b[N];
int main(){
	scanf("%d",&T);
	rep(i,T){
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		a[0]=a[n+1]=0;
		rep(i,n)a[i]=s[i]=='1';
		rep(i,min(n,m)){
			rep(j,n){
				if(a[j])b[j]=1;
				else{
					if(a[j+1]^a[j-1])b[j]=1;
					else b[j]=0;
				}
			}
			rep(j,n)a[j]=b[j];
		}
		rep(j,n)printf("%d",a[j]);
		puts("");
	}
	return 0;
}