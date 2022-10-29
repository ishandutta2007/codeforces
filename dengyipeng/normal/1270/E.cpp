#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1005
#define ll long long 
using namespace std;

int n,i,j,k,x[maxn],y[maxn],c[2][2],bz,ans[maxn];

void count(){
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++) c[x[i]&1][y[i]&1]++;
	bz=(c[0][0]>0)+(c[1][0]>0)+(c[0][1]>0)+(c[1][1]>0);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),x[i]+=1e6,y[i]+=1e6;
	count();
	while (bz==1) {
		for(i=1;i<=n;i++) x[i]/=2,y[i]/=2;
		count();
	}
	if (c[0][0]+c[1][1]&&c[0][1]+c[1][0]){
		for(i=1;i<=n;i++) 
			if (((x[i]&1)+(y[i]&1))&1)
				ans[++ans[0]]=i;
	} else{
		if (c[0][0]+c[1][1]){
			for(i=1;i<=n;i++) if ((x[i]&1)&&(y[i]&1))
				ans[++ans[0]]=i;
		} else {
			for(i=1;i<=n;i++) if ((x[i]&1)&&!(y[i]&1))
				ans[++ans[0]]=i;
		}
	}
	printf("%d\n",ans[0]);
	for(i=1;i<=ans[0];i++) 
		printf("%d ",ans[i]);
}