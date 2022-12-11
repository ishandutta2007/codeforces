#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}

int n,m;
int main()
{
	n=read(),m=read();
	if (n==1&&m==1) return puts("0"),0;
	if (m<=1) return puts("1"),0;
	n--,m--;
	if (n&1)
	{
		if (m<=n/2) return printf("%d\n",m+1),0;
		return printf("%d\n",n/2+1-(m-n/2)),0;
	}
	if (m<n/2)  return printf("%d\n",m+1),0;
	if (m==n/2) return printf("%d\n",n/2),0;
	printf("%d\n",n/2-(m-n/2));
	return 0;
}