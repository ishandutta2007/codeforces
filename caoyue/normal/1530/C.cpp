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
const int N=5e5+7;
const int INF=1e9+7;
int a[N],b[N],aa[N],bb[N];
int T,n;
bool check(int k){
	int c1=0,c2=0;
	rep(i,n)aa[++c1]=a[i];
	rep(i,k)aa[++c1]=100;
	rep(i,k)bb[++c2]=0;
	rep(i,n)bb[++c2]=b[i];
	int s1=0,s2=0;
	REP(i,(n+k)/4+1,n+k){
		s1+=aa[i];
		s2+=bb[i];
	}
	return (s1>=s2);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int l=0,r=3*n;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid;
		}
		if(check(l))printf("%d\n",l);
		else printf("%d\n",r);
	}
	return 0;
}