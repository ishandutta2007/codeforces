#include<cstdio>
using namespace std;
const int MOD=1e9+7;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	n=qp(2*n+2,m)*1ll*qp(n+1,MOD-2)%MOD*(n+1-m)%MOD;
	printf("%d",n);
	return 0;
}