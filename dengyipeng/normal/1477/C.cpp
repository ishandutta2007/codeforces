#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 5005
#define db double
using namespace std;

const db Pi=acos(-1);
int n,i,j,k,x[maxn],y[maxn],p[maxn];

int check(int i,int j,int k){
	return 1ll*(x[j]-x[i])*(x[k]-x[i])+1ll*(y[j]-y[i])*(y[k]-y[i])<=0;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	p[1]=1,p[2]=2;
	for(i=3;i<=n;i++) {
		int tp=0;
		for(j=1;j<=i;j++){
			if (j<i-1&&check(p[j],p[j+1],i)) continue;
			if (j>2&&check(p[j-1],p[j-2],i)) continue;
			if (j>1&&j<=i-1&&check(i,p[j-1],p[j])) continue;
			for(k=i;k>j;k--) p[k]=p[k-1];
			p[j]=i,tp=1;break;
		}
		if (!tp) printf("-1"),exit(0);
	}
	for(i=1;i<=n;i++) printf("%d ",p[i]);
}