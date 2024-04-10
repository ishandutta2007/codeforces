#include<bits/stdc++.h>
#define int long long 
const int N=2e5+3;
int n,m,a[N],b,s;
int G(int a,int b){return b?G(b,a%b):a;}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),i>1&&(s=G(s,std::abs(a[i]-a[i-1])));
	for(;m--;)scanf("%lld",&b),printf("%lld ",G(a[1]+b,s));puts("");
	return 0;
}