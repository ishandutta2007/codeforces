#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char c[1003][1003];
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(int i=1+(n%3==0);i<=n;){
		for(int j=1;j<=m;j++)c[i][j]='X';
		i+=3;
		if(i>n)break;
		int p=1;
		if(m==1||(c[i-1][2]!='X'&&c[i-2][2]!='X'))p=1;
		else p=2;
		c[i-1][p]=c[i-2][p]='X';
	}
	for(int i=1;i<=n;i++)puts(c[i]+1);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}