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
typedef long long ll;

int a,b,c;
ll ans;
int main()
{
	a=read(),b=read(),c=read();
	ans=c*2;
	int d=min(a,b);
	ans+=d*2; a-=d; b-=d;
	if (b) ans++;
	if (a) ans++;
	printf("%I64d\n",ans);
	return 0;
}