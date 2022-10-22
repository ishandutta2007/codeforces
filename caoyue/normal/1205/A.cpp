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
const int N=2e5+7;
const int INF=1e9+7;
int n;
int a[N];
int main(){
	scanf("%d",&n);
	if(n%2==0)puts("NO");
	else{
		puts("YES");
		rep(i,n){
			a[i]=i*2-1,a[i+n]=i*2;
			if(i&1)swap(a[i],a[i+n]);
		}
		rep(i,2*n)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}