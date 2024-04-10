#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int mo=1000000007;
int f[2][410][410],i,n,m,l,ans,t,j,k;
void plus(int &x,int y){
	x=(0ll+x+y)%mo;
}
int main(){
	scanf("%d%d%d",&n,&m,&l);
	if(n>m)return puts("0"),0;
	t=0;
	f[t][0][0]=1;
	for(i=1;i<=m;++i){
		for(j=0;j<=n;++j)
			for(k=0;k<=j;++k)
				plus(f[t^1][j][k],(i==l?0:f[t][j][k])+f[t][j-1][k-1]);
		for(j=0;j<=n;++j)
			for(k=0;k<=j;++k){
				plus(f[t^1][j][k],f[t^1][j][k+1]);
				f[t][j][k]=0;
			}
		t^=1;
	}
	ans=f[t][n][0];
	for(i=1;i<=n;++i)ans=(long long)ans*i%mo;
	printf("%d\n",ans);
}