#include<cstdio>
#define int long long
const int N=1e5+2;
int n,m,d,a[N],p,k,s,t;
signed main(){
	scanf("%I64d%I64d%I64d",&n,&m,&d);
	for(int i=1;i<=m;i++)scanf("%lld",a+i);
	int p=1,k=0;
	for(;k<m;){
	  p+=(a[k+1]-p)/d*d;
	  t=p+d-1;
	  for(;a[k+1]<=t;k++)p++;
	  s++;
	}printf("%I64d",s);
	return 0;
}