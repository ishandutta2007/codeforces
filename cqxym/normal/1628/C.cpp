#include<stdio.h>
#include<bitset>
using namespace std;
#define R register int
struct State{
	bitset<1000>X;
	int A;
	inline void operator^=(State&S){
		X^=S.X;
		A^=S.A;
	}
}f[2][1000],g[1000];
int a[1000][1000],res[1000];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		for(R j=0;j!=n;j++){
			scanf("%d",a[i]+j);
		}
	}
	State T;
	T.A=0;
	T.X.reset(0);
	for(R i=0;i!=n;i++){
		f[0][i].X.reset(0);
		f[0][i].X[i]=1;
		f[0][i].A=0;
	}
	for(R i=0;i!=n;i++){
		f[1][i].X.reset(0);
		f[1][i].A=a[0][i];
		if(i!=0){
			f[1][i]^=f[0][i-1];
		}
		if(i!=n-1){
			f[1][i]^=f[0][i+1];
		}
		T^=f[0][i];
		T^=f[1][i];
	}
	for(R i=2;i!=n;i++){
		for(R j=0;j!=n;j++){
			if(j!=0){
				f[i&1][j]^=f[i&1^1][j-1];
			}
			if(j!=n-1){
				f[i&1][j]^=f[i&1^1][j+1];
			}
			f[i&1][j].A^=a[i-1][j];
			T^=f[i&1][j];
		}
	}
	/*for(R i=0;i!=n;i++){
		printf("I%d\n",i);
		for(R j=0;j!=n;j++){
			printf("%d ",f[1][i].X[j]==1);
		}
		printf("%d\n",f[1][i].A);
	}*/
	for(R i=0;i!=n;i++){
		g[i]=f[n&1][i];
		if(i!=0){
			g[i]^=f[n&1^1][i-1];
		}
		if(i!=n-1){
			g[i]^=f[n&1^1][i+1];
		}
		g[i].A^=a[n-1][i];
	}
	/*for(R i=0;i!=n;i++){
		for(R j=0;j!=n;j++){
			printf("%d ",g[i].X[j]==1);
		}
		printf("%d\n",g[i].A);
	}*/
	for(R i=0;i!=n;i++){
		if(g[i].X[i]==0){
			for(R j=i+1;j!=n;j++){
				if(g[j].X[i]!=0){
					State t=g[i];
					g[i]=g[j];
					g[j]=t;
					break;
				}
			}
		}
		for(R j=i+1;j!=n;j++){
			if(g[j].X[i]!=0){
				g[j]^=g[i];
			}
		}
	}
	for(R i=n-1;i!=-1;i--){
		res[i]=g[i].A;
		for(R j=i+1;j!=n;j++){
			if(g[i].X[j]!=0){
				res[i]^=res[j];
			}
		}
	}
	/*for(R i=0;i!=n;i++){
		printf("%d ",res[i]);
	}
	puts("");*/
	int ans=T.A;
	for(R i=0;i!=n;i++){
		if(T.X[i]!=0){
			ans^=res[i];
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
/*
1
4
2 4 1 6
3 7 3 10
15 9 4 2
12 7 15 1

3
2
1 5
5 1
4
2 4 1 6
3 7 3 10
15 9 4 2
12 7 15 1
4
1 14 8 9
3 1 5 9
4 13 11 1
1 15 4 11
*/