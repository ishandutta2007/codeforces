#include<stdio.h>
#define R register int
#define I inline
#define N 400000
I void Min(int&x,const int y){
	if(x>y){
		x=y;
	}
}
char s[100002];
int dp[N][3][3];
I void Merge(auto A,auto B,auto C){
	for(R i=0;i!=3;i++){
		for(R j=i;j!=3;j++){
			A[i][j]=N;
		}
	}
	for(R i=0;i!=3;i++){
		for(R j=i;j!=3;j++){
			for(R k=j;k!=3;k++){
				Min(A[i][k],B[i][j]+C[j][k]);
			}
		}
	}
}
I void Init(int p,int lf,int rt){
	if(lf==rt){
		int x=s[lf]-'a';
		dp[p][x][x]=1;
	}else{
		Init(p<<1,lf,lf+rt>>1);
		Init(p<<1|1,lf+rt+2>>1,rt);
		Merge(dp[p],dp[p<<1],dp[p<<1|1]);
	}
}
I void Modify(int p,int lf,int rt,int x){
	if(lf==rt){
		for(R i=0;i!=3;i++){
			dp[p][i][i]=0;
		}
		x=s[x]-'a';
		dp[p][x][x]=1;
	}else{
		int mid=lf+rt>>1;
		if(x>mid){
			Modify(p<<1|1,mid+1,rt,x);
		}else{
			Modify(p<<1,lf,mid,x);
		}
		Merge(dp[p],dp[p<<1],dp[p<<1|1]);
	}
}
int main(){
	int n,q,x;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	Init(1,1,n);
	for(R i=0;i!=q;i++){
		scanf("%d",&x);
		scanf(" %c",s+x);
		Modify(1,1,n,x);
		printf("%d\n",dp[1][0][2]);
	}
	return 0;
}