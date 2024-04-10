#include<stdio.h>
#define R register int
int f[2001][2001],sufsum[2][2002][26];
char s[2001],t[2001];
inline void Min(int&x,int y){
	x=x<y?x:y;
}
inline void Solve(){
	int n;
	scanf("%d\n",&n);
	for(R i=1;i<=n;i++){
		s[i]=getchar();
	}
	getchar();
	for(R i=1;i<=n;i++){
		t[i]=getchar();
	}
	for(R i=0;i!=26;i++){
		sufsum[0][n+1][i]=sufsum[1][n+1][i]=0;
	}
	for(R i=n;i!=0;i--){
		for(R j=0;j!=26;j++){
			sufsum[0][i][j]=sufsum[0][i+1][j];
			sufsum[1][i][j]=sufsum[1][i+1][j];
		}
		sufsum[0][i][s[i]-'a']++;
		sufsum[1][i][t[i]-'a']++;
	}
	for(R i=0;i!=26;i++){
		if(sufsum[0][1][i]!=sufsum[1][1][i]){
			puts("-1");
			return;
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=0;j!=i;j++){
			f[i][j]=1e9;
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=i;j<=n;j++){
			f[i][j]=f[i-1][j]+1;
			if(s[i]==t[j]){
				Min(f[i][j],f[i-1][j-1]);
			}
			int tem=t[j]-'a';
			if(sufsum[0][i+1][tem]>sufsum[1][j+1][tem]){
				Min(f[i][j],f[i][j-1]);
			}
		}
	}
	printf("%d\n",f[n][n]);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}