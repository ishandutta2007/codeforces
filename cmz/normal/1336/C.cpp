#include <bits/stdc++.h>
using namespace std;
char s[3001],t[3001];
int ns,nt,f[3001][3001];
const int P=998244353;
int add(int a,int b) {
	a+=b;
	return(a>=P)?a-P:a;
}
int main() {
	scanf("%s%s",s+1,t+1);
	ns=strlen(s+1);
	nt=strlen(t+1);
	for(int i=ns; i; i--)
		for(int j=i; j<=ns; j++) {
			if(i==j) {
				if(s[1]==t[i]||i>nt)f[i][j]=2;
				else f[i][j]=0;
				continue;
			}
			if(s[j-i+1]==t[i]||i>nt)f[i][j]=add(f[i][j],f[i+1][j]);
			if(s[j-i+1]==t[j]||j>nt)f[i][j]=add(f[i][j],f[i][j-1]);
		}
	int ans=0;
	for(int i=nt; i<=ns; i++)ans=add(ans,f[1][i]);
	printf("%d\n",ans);
}