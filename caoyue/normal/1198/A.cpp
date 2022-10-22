#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=4e5+7;
const int INF=1e9+7;
int n,I,cnt=0;
map<int,int>mp;
int a[N],g[N];

int main(){
	scanf("%d%d",&n,&I);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)mp[a[i]]=0;
	sort(a+1,a+n+1);
	for(map<int,int>::iterator s=mp.begin();s!=mp.end();s++){
		mp[s->first]=++cnt;
		g[cnt]=s->first;
	}
	int k=I*8/n,v,ans=INF;
	if(k>=30)v=INF;
	else v=1<<k;
	mp[INF*2]=cnt+1;
	rep(i,n){
		int d=upper_bound(a+1,a+n+1,g[min(mp[a[i]]+v-1,cnt)])-a;
		ans=min(ans,i-1+(n-d+1));
	}
	printf("%d\n",ans); 
	return 0;
}