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
const int N=3.5e7+7;
const int M=4e5+7;
const int INF=1e9+7;
int a[M];
int s[N];
int n,ans=0;

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	for(int i=24;~i;i--){
		rep(j,n)a[j]%=(1<<(i+1));
		int t=(1<<i),h=0;
		rep0(j,t*2)s[j]=0;
		rep(j,n)s[a[j]]++;
		rep(j,t*2)s[j]+=s[j-1];
		rep(j,n){
			if(a[j]&t)h+=(s[2*t-a[j]-1]+n-s[3*t-a[j]-1]);
			else h+=(s[2*t-a[j]-1]-s[t-a[j]-1]);
			if((a[j]+a[j])&t)h--;
		}
		if((h/2)&1)ans|=(1<<i);
	}
	printf("%d\n",ans);
	return 0;
}