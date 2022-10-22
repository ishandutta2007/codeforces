#include<bits/stdc++.h>
const int N=1e6+3;
int n,g[N],ans,s0,s1;char a[N];
int main(){
	scanf("%d%s",&n,a+1);
	for(int i=1;i<=n;i++){
	  if(a[i]==')'){
		g[i]=i-1;
		for(;a[g[i]]==')';g[i]=g[g[i]]-1);
		if(g[i]<0)g[i]=0;
	  }
	  else g[i]=0;
	}
	s0=s1=0,ans=0;
	for(int i=1;i<=n;i++){
	  s0+=a[i]=='(';
	  s1+=a[i]==')';
	  if(s0==s1){
		if(!g[i])ans+=s0+s1;
		s0=s1=0;
	  }
	}
	printf("%d\n",s0+s1?-1:ans);
	return 0;
}