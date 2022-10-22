#include<bits/stdc++.h>
const int N=1e5+3;
int n,ans,b[26];char a[N];
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%s",a+1),n=strlen(a+1);
	if(n==1){puts("0");continue;}
	ans=0;
	for(int i=2,x;i<=n;i++){
	  for(int j=i-2;j<=i+2;j++)if(j>=1&&j<=n)
		b[a[j]-'a']=1;
	  for(x=0;b[x];++x);
	  for(int j=i-2;j<=i+2;j++)if(j>=1&&j<=n)
		b[a[j]-'a']=0;
	  if(a[i]==a[i-1]||i>2&&a[i-2]==a[i])a[i]=x+'a',++ans;
	}
	printf("%d\n",ans);
	}return 0;
}