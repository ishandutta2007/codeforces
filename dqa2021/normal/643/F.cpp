#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef unsigned uint;
uint qpow(uint x,uint y=(1U<<31)-1){
	uint res=1;
	for (;y;y>>=1,x*=x)
		if (y&1) res*=x;
	return res;
}

int n,p,q;
uint C[150];
int main()
{
	n=read(),p=read(),q=read();
	p=min(p,n-1);
	for (int i=0;i<=p;i++){
		int tot2=0; uint A=1,B=1;
		for (int j=0;j<i;j++){
			uint x=n-j;
			while (!(x&1)) tot2++,x>>=1;
			A*=x;
		}
		for (int j=1;j<=i;j++){
			uint x=j;
			while (!(x&1)) tot2--,x>>=1;
			B*=x;
		}
//		printf("A %u B %u tot %d\n",A,B,tot2);
		if (tot2>=32) C[i]=0;
		else C[i]=A*qpow(B)<<tot2;
//		printf("c %d = %u\n",i,C[i]);
	}
	uint ans=0;
	for (int i=1;i<=q;i++){
		uint S=1,subans=0;
		for (int j=0;j<=p;j++){
			subans+=C[j]*S;
			S*=i;
		}
		ans^=i*subans;
	}
	printf("%u\n",ans);
	return 0;
}