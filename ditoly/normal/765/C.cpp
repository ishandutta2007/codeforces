#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
int main()
{
	int k,a,b,ans;
	k=read();a=read();b=read();
	if(a<k&&b%k)return 0*puts("-1");
	if(b<k&&a%k)return 0*puts("-1");
	printf("%d",a/k+b/k);
}