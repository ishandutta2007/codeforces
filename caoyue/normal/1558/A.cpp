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
int T,a,b;
bool ok[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		rep0(i,a+b+1)ok[i]=0;
		int n=a+b;
		rep0(i,2){
			int u=n/2;
			int v=n-n/2;
			if(i)if(u<v)swap(u,v);
			if(!i)if(u>v)swap(u,v);
			rep0(j,a+b+1){
				int t=u+a+j;
				if(t%2==1)continue;
				t/=2;
				if(t-j<0)continue;
				if(t-a<0)continue;
				if(t-u<0)continue;
				if(v-(t-u)<0)continue;
				ok[j]=1;
			}
		}
		int ans=0;
		rep0(i,a+b+1)ans+=ok[i];
		printf("%d\n",ans);
		rep0(i,a+b+1)if(ok[i])printf("%d ",i);
		puts("");
	}
	return 0;
}