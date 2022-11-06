#include<bits/stdc++.h>
using namespace std;
char a[200002],b[200002];
int n,m,L[200002],R[200002];
int main(){
	int ans=0,i,j;
	scanf("%d%d",&n,&m);
	scanf("%s%s",a+1,b+1);
	for(i=j=1;j<=m;){
		for(;a[i]!=b[j];++i);
		L[j]=i;
		++j;++i;
	}
	for(i=n,j=m;j>=1;){
		for(;a[i]!=b[j];--i);
		R[j]=i;
		--j;--i;
	}
	for(i=1;i<m;++i)ans=max(ans,R[i+1]-L[i]);
	printf("%d\n",ans);
	return 0;
}