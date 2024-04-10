#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;/*1
3 4 2 1
1 2 3 59
*/
typedef long long ll;
const int N=3000,M=3000;
int n,m,a,b;
int g0,x,y,z;
int hi[N+1][M+1];
int q[N],head,tail;
int mn[N+1][M+1];
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&a,&b,&g0,&x,&y,&z);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)hi[i][j]=g0,g0=(1ll*g0*x+y)%z;
	for(int i=1;i<=n;i++){
		head=tail=0;
		for(int j=1;j<b;j++){
			while(head<tail&&hi[i][q[tail-1]]>=hi[i][j])tail--;
			q[tail++]=j;
		}
		for(int j=b;j<=m;j++){
			if(head<tail&&q[head]==j-b)head++;
			while(head<tail&&hi[i][q[tail-1]]>=hi[i][j])tail--;
			q[tail++]=j;
			mn[i][j]=hi[i][q[head]];
		}
	}
	ll ans=0;
	for(int j=b;j<=m;j++){
		head=tail=0;
		for(int i=1;i<a;i++){
			while(head<tail&&mn[q[tail-1]][j]>=mn[i][j])tail--;
			q[tail++]=i;
		}
		for(int i=a;i<=n;i++){
			if(head<tail&&q[head]==i-a)head++;
			while(head<tail&&mn[q[tail-1]][j]>=mn[i][j])tail--;
			q[tail++]=i;
			ans+=mn[q[head]][j];
		}
	}
	printf("%lld",ans);
	return 0;
}
/*1
3 4 2 1
1 2 3 59
*/