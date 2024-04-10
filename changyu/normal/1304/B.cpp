#include<bits/stdc++.h>
const int N=103;
int n,m,f[N],g[N],s,tmp[N],k,used[N];char a[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++){
		for(int k=1;k<=m;k++)
		  if(a[i][m-k+1]!=a[j][k])goto Brk;
		f[i]=j,f[j]=i,s+=2;
		Brk:;
	  }
	for(int i=1;i<=n;i++){
	  for(int j=1;j+j<=m;j++)
		if(a[i][m-j+1]!=a[i][j])goto Brk1;
	  g[i]=1,s++;break;
	  Brk1:;
	}
	printf("%d\n",s*m);
	for(int i=1;i<=n;i++)if(f[i]&&!used[f[i]]){
	  used[i]=1,tmp[++k]=f[i];
	  printf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++)if(g[i]){printf("%s",a[i]+1);break;}
	for(;k;k--)printf("%s",a[tmp[k]]+1);puts("");
	return 0;
}