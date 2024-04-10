#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
char s[3][200005];
int a[3],n,ans[300005];
bool bo[3];
void work(int x,int y,bool f){
	int m=0,i,j;
	//puts("haha");
	for(i=j=1;i<=n+n||j<=n+n;){
		while(s[x][i]!=f&&i<=n+n){
			ans[++m]=1-f;
			++i;
		}
		while(s[y][j]!=f&&j<=n+n){
			ans[++m]=1-f;
			++j;
		}
		if(i<=n+n||j<=n+n)ans[++m]=0+f;
		if(i<=n+n)++i;if(j<=n+n)++j;
	}
	for(i=1;i<=m;++i)printf("%d",ans[i]);
	puts("");
}
int main(){
	int T,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<=2;++i){
			scanf("%s",s[i]+1);
			for(j=1;j<=n+n;++j)s[i][j]-='0';
			a[i]=0;
		}
		for(i=0;i<=2;++i){
			for(j=1;j<=n+n;++j)if(s[i][j])++a[i];
		}
		for(i=0;i<=2;++i)bo[i]=(a[i]>=n);
		//printf("%d %d %d\n",bo[0],bo[1],bo[2]);
		if(bo[0]==bo[1])work(0,1,bo[0]);
		else if(bo[0]==bo[2])work(0,2,bo[0]);
		else work(1,2,bo[1]);
	}
	return 0;
}