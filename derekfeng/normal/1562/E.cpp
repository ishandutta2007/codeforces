#include<bits/stdc++.h>
using namespace std;
int Tc,n,ans,f[5003];
char c[5003];
int lcp[5003][5003];
bool bigger(int i,int j){
	if(lcp[i][j]==n-i+1)return 0;
	return c[i+lcp[i][j]]>c[j+lcp[i][j]];
}
int got(int i,int j){
	return bigger(i,j)?f[j]+n+1-i-lcp[i][j]:0;
}
void solve(){
	scanf("%d%s",&n,c+1);
	for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++)lcp[i][j]=0;
	for(int i=n;i;i--)for(int j=n;j;j--)
		lcp[i][j]=c[i]==c[j]?lcp[i+1][j+1]+1:0;
	ans=f[1]=n;
	for(int i=2;i<=n;i++){
		f[i]=n-i+1;
		for(int j=1;j<i;j++)f[i]=max(f[i],got(i,j));
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
}
int main(){for(scanf("%d",&Tc);Tc--;solve());}