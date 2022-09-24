#include <cstdio>

using namespace std;

typedef long long LL;

LL f(LL a)
{
	if(a==0) return 0;
	
	LL i,b,k,l,s=0;
	for(i=0,k=1; k<=a; i++,k*=2);
	b=k-1,i--,k/=2;
	
	for(l=k/2;l>=1;l/=2){
		if(b-l <= a) s++;
	}
	
	return i*(i-1)/2+s;
}

int main()
{
	LL a,b;
	
	scanf("%I64d %I64d",&a,&b);
	
	printf("%I64d\n",f(b)-f(a-1));
	
	return 0;
}