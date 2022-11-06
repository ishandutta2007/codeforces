#include<bits/stdc++.h>
using namespace std;
char s[1002];
int a[1002],b[1002],n;
bool check(){
	for(int i=1;i<=n;++i)if(a[i]!=b[i])return 0;
	return 1;
}
int main(){
	int T,m,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for(i=1;i<=n;++i)a[i]=s[i]-'0';a[n+1]=a[0]=0;
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j){
				if(a[j])b[j]=1;
				else if(a[j-1]^a[j+1])b[j]=1;
				else b[j]=0;
			}
			if(check())break;
			for(j=1;j<=n;++j)a[j]=b[j];
		}
		for(i=1;i<=n;++i)printf("%d",a[i]);
		puts("");
	}
	return 0;
}