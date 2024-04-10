#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 21
#define maxm 5005
using namespace std;

int n,i,j,k,p,q,a[maxm],bz[1<<maxn],f[1<<maxn],nm[30],tot,chr[30];
int L[30],R[30],Li[30],cnt[30],ans[30];
int cmp(int i,int j){return i<j;}

int main(){
	scanf("%d%d%d",&n,&p,&q); char ch=getchar();
	while (ch<'a'||ch>'z') ch=getchar();
	for(i=1;i<=n;i++) a[i]=ch-'a',ch=getchar();
	for(i=1;i<=n;i++) {
		if (!nm[a[i]]) nm[a[i]]=++tot,L[tot]=R[tot]=i,chr[tot]=a[i];
		k=nm[a[i]];
		L[k]=min(L[k],i),R[k]=max(R[k],i),cnt[k]++;
	}
	for(i=1;i<=tot;i++) Li[i]=i; sort(Li+1,Li+1+tot,cmp);
	for(int S=1;S<1<<tot;S++){
		int l=n+1,r=0,c=0;
		for(i=1;i<=tot;i++) if (S>>i-1&1)
			l=min(l,L[i]),r=max(r,R[i]),c+=cnt[i];
		bz[S]=c*q/p>=r-l+1;
	}
	f[0]=1;
	for(int S=1;S<1<<tot;S++){
		if (bz[S])
		for(i=1;i<=tot;i++) if (S>>i-1&1)
			f[S]|=f[S^(1<<i-1)];
		if (f[S]) continue;
		i=1; while (S>>Li[i]-1&1^1) i++;
		k=R[Li[i]]; int T=1<<Li[i]-1; i++;
		while (i<=tot){
			while (i<=tot&&((S>>Li[i]-1&1^1)||L[Li[i]]<=k)){
				if (S>>Li[i]-1&1)
					k=max(k,R[Li[i]]),T|=1<<Li[i]-1;
				i++;
			}
			if (i<=tot){
				f[S]|=f[T]&f[S^T];
				k=max(k,R[Li[i]]),T|=1<<Li[i]-1,i++;
			}
		}
	}
	k=(1<<tot)-1;
	for(i=1;i<=tot;i++) if (f[k^(1<<i-1)]) ans[chr[i]]=1;
	int c=0;
	for(i=0;i<26;i++) c+=ans[i];
	printf("%d ",c);
	for(i=0;i<26;i++) if (ans[i]) putchar('a'+i),putchar(' ');
}