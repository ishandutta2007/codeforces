#include<cstdio>
const int N=103;
int n,a[N][N],b;
inline bool Prime(int n){
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++)
	  if(n%i==0)return 0;
	return 1;
}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		a[i][j]=1;
	for(b=n;;b++)
	  if(!Prime(b-n+1)&&Prime(b))
		break;
	for(int i=1;i<=n;i++)
	  a[i][i]=b-n+1;
	for(int i=1;i<=n;i++){
	  for(int j=1;j<=n;j++)
		printf("%d ",a[i][j]);
	  puts("");
	}
	}return 0;
}