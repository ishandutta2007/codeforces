#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[2333],b[2333],c[2333],p[2333]; 
int main(){
	int i,j,k,m[5],mm[5],nm=0,mn=0;
	scanf("%d",&n);
	memset(m,0,sizeof(m));
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	for(i=1;i<=n;i++)if(a[i]!=b[i])m[mn++]=i;
	for(i=1;i<=n;i++){
		if(i==m[0]||i==m[1]);
		else p[i]=a[i];
		c[p[i]]=1;
	}
	for(i=1;i<=n;i++)if(!c[i])
		mm[nm++]=i;
	p[m[0]]=mm[0];
	p[m[1]]=mm[1];
	for(i=1,j=k=0;i<=n;i++){
		j+=(a[i]!=p[i]);
		k+=(b[i]!=p[i]);
	}
	if(j!=1||k!=1){
		p[m[1]]=mm[0];
		p[m[0]]=mm[1];
	}
	for(i=1;i<=n;i++)printf("%d ",p[i]);
	return 0; 
}