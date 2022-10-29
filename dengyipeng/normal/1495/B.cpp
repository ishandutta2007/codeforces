#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 100005
using namespace std;

int n,i,j,k,a[maxn],f[maxn],g[maxn],mx,cnt;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=2;i<=n;i++) if (a[i-1]<a[i]) f[i]=f[i-1]+1;
	for(i=n-1;i>=1;i--) if (a[i+1]<a[i]) g[i]=g[i+1]+1;
	for(i=1;i<=n;i++) mx=max(mx,max(f[i],g[i]));
	for(i=1;i<=n;i++) cnt+=(f[i]==mx)+(g[i]==mx);
	if (cnt>=3) printf("0\n"),exit(0);
	if (cnt==2){
		for(i=1;i<=n;i++) {
			if (f[i]==mx&&g[i]!=mx) printf("0\n"),exit(0);
			if (g[i]==mx&&f[i]!=mx) printf("0\n"),exit(0);
		}
	}
	if (cnt==1) printf("0\n"),exit(0);
	printf("%d\n",mx&1^1);
}