#include<cstdio>
typedef long long ll;
const int M=998244353;
inline int Pow(int a,ll m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int n,m,l,r,t;
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&r);
	t=Pow(r-l+1,(ll)n*m);
	if(n&m&1)return 0*printf("%d\n",t);
	if(r-l+1&1)++t,t%=M;
	for(;t&1;t+=M);
	t>>=1;
	return 0*printf("%d\n",t);
}