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
const int N=107;
const int INF=1e9+7;
int a[N];
int n,k,ans=0,gg=0;
 
int main(){
	cin>>n>>k;
	rep(i,n)cin>>a[i],gg+=a[i];
	rep(b,k){
		int hh=gg;
		for(int j=b;j<=n;j+=k)hh-=a[j];
		if(hh<0)ans=max(ans,-hh);
		else ans=max(ans,hh);
	}
	cout<<ans<<endl;
	return 0;
}