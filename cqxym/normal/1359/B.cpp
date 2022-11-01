#include<stdio.h>
#define R register int
char c[101][1001];
inline void Solve(){
	int n,m,x,y,ct1=0,ct2=0;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(R i=1;i<=n;i++){
		getchar();
		int lt=0,len;
		for(R j=1;j<=m;j++){
			c[i][j]=getchar();
			if(c[i][j]=='*'){
				len=j-lt-1;
				ct1+=len&1;
				ct2+=len>>1;
				lt=j;
			}
		}
		len=m-lt;
		ct1+=len&1;
		ct2+=len>>1;
	}
	if(x<<1>y){
		printf("%d\n",ct1*x+ct2*y);
	}else{
		printf("%d\n",(ct1+(ct2<<1))*x);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}