#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep0(i,n) REP(i,0,n-1)
#define rep(i,n) REP(i,1,n)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
const int N=107;
const int INF=1e9+7;
struct pir{int x,y;}a[N];
int b[N];
int n,cnt=0,k;
bool cmp(pir s,pir t){return s.x<t.x;}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n)scanf("%d",&a[i].x),a[i].y=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int q=i;
		b[++cnt]=a[i].y;
		while(a[i+1].x==a[i].x)i++;
	}
	if(cnt<k)printf("NO\n");
	else{
		printf("YES\n");
		sort(b+1,b+k+1);
		rep(i,k)printf("%d ",b[i]);
		cout<<endl;
	}
	return 0;
}