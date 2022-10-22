#include<cstdio>
#define int long long
int n,p,c;
inline int Count(int a){int s=0;for(;a;a-=a&-a)s++;return s;}
signed main(){
	scanf("%lld%lld",&n,&p);
	for(;;){
	  n-=p;c++;
	  if(n<c)return 0*puts("-1");
	  if(Count(n)<=c)return 0*printf("%lld",c);
	}
	return 0;
}