#include<cstdio>
using namespace std;
unsigned gcd(unsigned a,unsigned b){return b?gcd(b,a%b):a;}
unsigned n,p,q,ans,binom[200],t[200],res,f;
int main(){
	scanf("%u%u%u",&n,&p,&q);
	t[binom[0]=1]=n;
	for(int i=2;i<=p;++i) t[i]=t[i-1]-1;
	for(int i=1;i<=p;++i){
		res=i;
		for(int j=1;j<=p;++j) f=gcd(t[j],res),t[j]/=f,res/=f;
		for(int j=binom[i]=1;j<=i;++j) binom[i]*=t[j];
	}
	res=0;
	for(int i=1,j=0;i<=q;ans^=res*(unsigned)i,++i,res=0)
		for(j=0,f=1;j<=p&&j<n;++j,f*=i) res+=binom[j]*f;
	printf("%u",ans);
	return 0;
}