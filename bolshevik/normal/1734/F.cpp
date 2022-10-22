#include<cstdio>
using namespace std;
int T;long long n,m,f[65][2][2][2];
#define v _+((n>>i)&1)+$>1
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",f[0][0][1][0])){
		scanf("%lld%lld",&n,&m);
		for(int i=0;i<61;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) for(int $=0;$<2;++$) f[i][j][k][$]=0;
		f[60][1][__builtin_popcountll(n)&1][0]=f[60][1][__builtin_popcountll(n)&1][1]=1;
		for(int i=60;i--;) for(int j=0;j<2;++j) for(int k=0;k<2;++k) for(int $=0;$<2;++$)
			for(int _=0;_<=(((m>>i)&1)|!j);++_) f[i][j&&(_==((m>>i)&1))][k^(v)][$]+=f[i+1][j][k][v];
	}
	return 0;
}