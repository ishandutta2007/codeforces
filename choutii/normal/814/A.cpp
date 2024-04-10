#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[233],b[233],c[233];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i),c[a[i]]=1;
	for(i=1;i<=m;i++)scanf("%d",b+i);
	for(i=1;i<=m;i++){
	if(c[b[i]]){
		puts("No");return 0;
	}
	c[b[i]]=1;
	}
	for(i=1,j=0;i<=n;i++)
		if(!a[i])a[i]=b[++j];
	for(i=1,j=0;i<n;i++)if(a[i]>a[i+1])j=1;
	if(!j&&m==1)puts("No");
	else puts("Yes");
	return 0;
}