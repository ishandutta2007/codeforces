#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int n,tp,res;
ll m;

inline ll read()
{
	ll n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

int main()
{
	register int i;
	n=read(); m=read();
	if (1LL*n*(n-1)/2<m) return 0*printf("Impossible");
	for (i=1;i<=n;++i) if (1LL*i*(i-1)/2>m) break;
	tp=i-1;
	res=m-1LL*tp*(tp-1)/2;
	for (i=1;i<=tp;++i) putchar('(');
	for (i=tp;i>res;--i) putchar(')');
	if (res) {printf("()"); for (i=res;i;--i) putchar(')'); ++tp;}
	for (i=tp+1;i<=n;++i) printf("()");
}