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
const int N=3e5+7;
const int M=1e6+7;
const int INF=1e9+7;
int T,n,q;
int p[M],a[N];
map<int,int>mp;

int main(){
	rep(i,1000)for(int j=1;j*i*i<=1000000;j++)p[i*i*j]=max(p[i*i*j],i);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);	
		mp.clear();
		rep(i,n)a[i]=a[i]/(p[a[i]]*p[a[i]]);
		rep(i,n){
			if(mp.count(a[i]))mp[a[i]]++;
			else mp[a[i]]=1;
		}
		int mx=0,sm=0;
		for(map<int,int>::iterator s=mp.begin();s!=mp.end();s++){
			if(mp[s->first]>mx)mx=mp[s->first];
			if(mp[s->first]%2==0||(s->first)==1)sm+=mp[s->first];
		}
		scanf("%d",&q);
		while(q--){
			ll x; scanf("%I64d",&x);
			if(!x)printf("%d\n",mx);
			else printf("%d\n",max(mx,sm));
		}
	}
	return 0;
}