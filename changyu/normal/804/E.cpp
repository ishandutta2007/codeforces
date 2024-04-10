#include<bits/stdc++.h>
int n,nn;
int main(){
	scanf("%d",&n);
	if(n*(n-1)/2&1)return 0*puts("NO");
	puts("YES");
	nn=n&~1;
	for(int i=1;i*2<=nn;i++)printf("%d %d\n",i,nn-i+1);
	if(n&1)for(int i=1;i*2<=n;i++)printf("%d %d\n",i,n);
	for(int i=2;i*2<=nn;i++)
		for(int j=i,k=(i-2+nn)%nn+1;j<i+nn/2;j++,k=(k-2+nn)%nn+1)
			printf("%d %d\n",std::min(j,k),std::max(j,k));
	for(int i=1;i*2<=nn;i++)
		for(int j=i+1,k=(i-2+nn)%nn+1;j<i+nn/2;j++,k=(k-2+nn)%nn+1)
			printf("%d %d\n",std::min(j,k),std::max(j,k));
	if(n&1)for(int i=1;i*2<=n;i++)printf("%d %d\n",n/2+i,n);
	return 0;
}