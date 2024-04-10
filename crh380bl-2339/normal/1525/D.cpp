#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int f[5005][5005];
int main(){
	int n,n1=0,n2=0,i,j,k,x;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(x==1)a[++n1]=i;
		else b[++n2]=i;
	}
	memset(f,0x3f,sizeof(f));
	for(j=0;j<=n2;++j)f[0][j]=0;
	if(!n1){
		puts("0");
		return 0;
	}
	sort(a+1,a+1+n1);sort(b+1,b+1+n2);
	for(i=1;i<=n1;++i){
		for(j=i;j<=n2;++j){
			if(j>i)f[i][j]=min(f[i][j],f[i][j-1]);
			f[i][j]=min(f[i][j],f[i-1][j-1]+abs(b[j]-a[i]));
		}
	}
	printf("%d\n",f[n1][n2]);
	return 0;
}