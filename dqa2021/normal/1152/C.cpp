#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int a,b;
ll ans=0x7fffffffffffffffLL;
int pos;
int main()
{
	scanf("%d%d",&a,&b);
	if (a>b) swap(a,b);
	if (b%a==0) return puts("0"),0;
	int c=b-a;
	for (int i=1;i*i<=c;i++)
		if (c%i==0)
		{
//			printf("%d and %d\n",i,c/i);
			ll tmp=(ll)(a%i==0?a:a-a%i+i)*(b%i==0?b:b-b%i+i)/i;
			int tmp2=(a%i==0?0:i-a%i);
			if (tmp<ans||tmp==ans&&tmp2<pos) ans=tmp,pos=tmp2;
//			printf("%lld %d\n",tmp,tmp2);
			
			int j=c/i;
			tmp=(ll)(a%j==0?a:a-a%j+j)*(b%j==0?b:b-b%j+j)/j;
			tmp2=(a%j==0?0:j-a%j);
			if (tmp<ans||tmp==ans&&tmp2<pos) ans=tmp,pos=tmp2;
//			printf("%lld %d\n",tmp,tmp2);
		}
	printf("%d\n",pos);
	return 0;
}