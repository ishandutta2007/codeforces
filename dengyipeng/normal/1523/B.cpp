#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 1005
#define ll long long 
using namespace std;

int T,n,m,i,j,k,p[maxn*5][3],tot;
ll a[maxn];
void add(int t,int x,int y){
	if (t==1) a[x]+=a[y],tot++,p[tot][0]=t,p[tot][1]=x,p[tot][2]=y;
	if (t==2) a[y]-=a[x],tot++,p[tot][0]=t,p[tot][1]=x,p[tot][2]=y;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		tot=0;
		for(i=1;i<=n;i+=2){
			add(1,i,i+1);
			add(2,i,i+1);
			add(1,i,i+1);
			add(1,i,i+1);
			add(2,i,i+1);
			add(1,i,i+1);
		}
//		for(i=1;i<=n;i++) printf("%lld ",a[i]); printf("\n");
		printf("%d\n",tot);
		for(i=1;i<=tot;i++)
			printf("%d %d %d\n",p[i][0],p[i][1],p[i][2]);
	}
}