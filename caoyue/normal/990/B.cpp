#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
const int N=2e5+7;
int n,k;
int a[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=1;;){
		int b=i,h=i;
		while(a[h+1]==a[h])h++;
		if(h==n)break;
		if(a[h+1]<=a[h]+k)ans-=(h-b+1);
		i=h+1;
	}
	printf("%d\n",ans);
	return 0;
}