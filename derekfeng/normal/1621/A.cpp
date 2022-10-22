#include<bits/stdc++.h>
using namespace std;
int T,n,K;
char ans[44][44];
void sol(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]='.';
	for(int i=1;i<=K;i++){
		if(i*2-1>n){
			puts("-1");
			return;
		}
		ans[2*i-1][2*i-1]='R';
	}
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)putchar(ans[i][j]);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}