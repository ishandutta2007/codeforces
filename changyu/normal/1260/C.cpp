#include<cstdio>
#include<algorithm>
#define int long long
int G(int a,int b){return b?G(b,a%b):a;}
int a,b,c,x,n,l;
signed main(){
	int T; 
	scanf("%lld",&T);
	for(;T--;){
	  scanf("%lld%lld%lld",&a,&b,&c);
	  x=std::max(a,b);
	  n=std::min(a,b);
	  a=x/G(x,n);
	  b=n/G(x,n);
	  --a;
	  puts((a-1)/b+1<c?"OBEY":"REBEL");
	}
	return 0;
}