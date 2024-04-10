#include<cstdio>
using namespace std;
int L,R,n=22,m,e[30][30];
int main(){
	scanf("%d%d",&L,&R);R-=L;
	for(int i=2;i<=21;++i) e[1][i]=1;
	for(int i=2;i<21;++i) for(int j=i+1;j<=21;++j) e[i][j]=(1<<(i-2));
	for(int i=20,s=0;i--;) if((R>>i)&1) e[i+2][22]=s+1,s+=(1<<i);
	e[1][22]=1;
	for(int i=1;i<=n;++i) if(e[1][i]) e[1][i]+=L-1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) m+=!!e[i][j];
	printf("YES\n%d %d\n",n,m);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(e[i][j]) printf("%d %d %d\n",i,j,e[i][j]);
	return 0;
}