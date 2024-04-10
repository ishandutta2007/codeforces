#include<bits/stdc++.h>
const int N=43;
int n,k;
char a[N][N];
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&k);
	if(k*2-1>n){puts("-1");continue;}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]='.';
	for(int i=1;i<=n&&i<=k*2;i+=2)a[i][i]='R';
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)putchar(a[i][j]);putchar('\n');}
	}return 0;
}