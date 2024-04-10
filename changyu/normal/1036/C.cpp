#include<cstdio>
typedef long long ll;
ll l,r,f[19][4],pow10[19];
inline ll Calc(ll a){
	if(a==pow10[18])return f[18][3];
	ll s=0;int k=1,l=3;for(;pow10[k]<=a;k++);
	for(;a&&l;k--)
	  if(a/pow10[k-1]){
		s+=(a/pow10[k-1]-1)*f[k-1][l-1]+f[k-1][l];
		a%=pow10[k-1];l--;
	  }
	return s;
}
int main(){
	pow10[0]=1;
	for(int i=1;i<=18;i++)pow10[i]=pow10[i-1]*10;
	f[0][0]=1;
	for(int i=1;i<=18;i++)
	  for(int j=0;j<=3;j++)
		f[i][j]=f[i-1][j]+(j?f[i-1][j-1]*9:0);
	for(int i=0;i<=18;i++)
	  for(int j=1;j<=3;j++)
		f[i][j]+=f[i][j-1];
	int T;scanf("%d",&T);for(;T--;){
	scanf("%I64d%I64d",&l,&r);
	printf("%I64d\n",Calc(r)-Calc(l-1));
	}return 0;
}