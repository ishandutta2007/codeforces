#include<stdio.h>
#include<stack>
using namespace std;
#define R register int
#define I inline
#define N 10002
int f[N][N],Last[N];
char A[N],B[N];
I int Read(char*S){
	char c=getchar();
	R i=0;
	do{
		i++;
		S[i]=c;
		c=getchar();
	}while(c!='\n');
	return i;
}
I void Init(int&n){
	stack<int>S;
	for(int i=1;i<=n;i++){
		if(A[i]=='.'){
			if(S.empty()==false){
				int t=S.top();
				S.pop();
				Last[i]=t-1;
			}
		}else{
			S.push(i);
		}
	}
}
I void Min(int&x,int y){
	x=x<y?x:y;
}
int main(){
	int n=Read(A),m=Read(B);
	for(R i=0;i<=n;i++){
		for(R j=0;j!=m+2;j++){
			f[i][j]=1e9;
		}
		Last[i]=-1;
	}
	Init(n);
	f[0][0]=0;
	for(R i=1;i<=n;i++){
		for(R j=0;j<=i&&j<=m;j++){
			Min(f[i][j],f[i-1][j]+1);
			if(A[i]==B[j]){
				Min(f[i][j],f[i-1][j-1]);
			}
			if(Last[i]!=-1){
				Min(f[i][j],f[Last[i]][j]);
			}
			if(A[i]=='.'){
				Min(f[i][j],f[i-1][j+1]);
			}
		}
	}
	printf("%d",f[n][m]);
	return 0;
}