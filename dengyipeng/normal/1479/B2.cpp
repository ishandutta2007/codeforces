#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
using namespace std;

int n,i,j,k,a[maxn],f[maxn],nex[maxn],bz[maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&k);
		if (k!=a[a[0]]) a[++a[0]]=k;
	}
	n=a[0],a[0]=0;
	for(i=n;i>=1;i--) nex[i]=bz[a[i]],bz[a[i]]=i;
	for(i=1;i<=n;i++) {
		f[i+1]=max(f[i+1],f[i]);
		j=nex[i]; 
		if (j)
			f[j]=max(f[j],f[i]+1+(a[i-1]==a[i+1]));
		j=nex[i-1];
		if (j)
			f[j]=max(f[j],f[i]+1);
	}
	printf("%d\n",n-f[n]);
}