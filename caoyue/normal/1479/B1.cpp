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
int n,cnt=0;
int a[N],c[N],l[N],g[N];

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int nw=i;
		while(a[i+1]==a[i])i++;
		l[++cnt]=i-nw;
		c[cnt]=a[i];
		g[cnt]=i;
	}
	l[0]=1;
	c[0]=0;
	l[cnt+1]=1;
	c[cnt+1]=-1;
	g[0]=-INF;
	g[cnt+1]=INF;
	int Ans=0;
	for(int i=0;i<=cnt;){
		int nw=i;
		i++;
		while(!l[i])i++;
		int s1=c[nw],s2=c[nw];
		REP(j,g[nw+1],g[i-1]){
			if(a[j]!=s1){
				if(a[j]!=s2){
					if(s2==c[i]){
						s2=a[j];
						Ans++;
					}
					else{
						s1=a[j];
						Ans++;
					}
				}
				else{
					s1=a[j];
					Ans++;
				}
			}
			else{
				if(a[j]!=s2){
					s2=a[j];
					Ans++;
				}
			}
		}
		Ans+=(s1!=c[i]);
		Ans+=(s2!=c[i]);
	}
	printf("%d\n",Ans-2);
	return 0;
}