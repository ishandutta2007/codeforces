#include<bits/stdc++.h>
const int N=2e5+3;
int n,ans[N];char a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s",&n,a+1);
	for(int i=1,j,t,r;i<=n;i++){
	  t=n-i+1;
	  if(a[i]=='>'){ans[i]=t;continue;}
	  for(j=i;a[j]=='<';j++);
	  r=j;
	  for(;j>=i;j--)ans[j]=t,--t;
	  i=r;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	for(int i=1,j,t,r;i<=n;i++){
	  t=i;
	  if(a[i]=='<'){ans[i]=t;continue;}
	  for(j=i;a[j]=='>';j++);
	  r=j;
	  for(;j>=i;j--)ans[j]=t,++t;
	  i=r;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	}return 0;
}