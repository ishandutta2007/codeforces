#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[105];
bool chk(){
	int i;
	for(i=1;i<=n;++i)if(a[i]!=a[1])return 0;
	return 1;
}
int main(){
	int T,i,j,k,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		s=0;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			s+=a[i];
		}
		sort(a+1,a+1+n);
		if(s<x){
			puts("YES");
			for(i=1;i<n;++i)printf("%d ",a[i]);
			printf("%d\n",a[n]);
			continue;
		}
		if(s==x){
			puts("NO");
			continue;
		}
		if(chk()&&x%a[1]==0){
			puts("NO");
			continue;
		}
		puts("YES");s=0;
		for(i=1;s<x&&i<=n;++i)s+=a[i];
		--i;
		for(j=1;j<i;++j)printf("%d ",a[j]);
		printf("%d",a[n]);
		for(;j<n;++j)printf(" %d",a[j]);puts("");
	}
	return 0;
}