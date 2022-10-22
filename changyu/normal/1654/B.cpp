#include<bits/stdc++.h>
const int N=2e5+3;
int n,b[26],ans;
char a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%s",a+1),n=strlen(a+1);
	for(int i=0;i<26;i++)b[i]=0;
	for(int i=1;i<=n;i++)b[a[i]-'a']=i;
	ans=n;
	for(int i=0;i<26;i++)if(b[i])ans=std::min(ans,b[i]); 
	printf("%s\n",a+ans);
	}return 0;
}