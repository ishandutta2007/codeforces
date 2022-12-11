#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (!flg) return x; return -x;
}
typedef long long ll;
const int Mod=998244353;

int n,m;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=(ll)x*x%Mod)
		if (y&1) res=(ll)res*x%Mod;
	return res;
}
int main()
{
	n=read(),m=read();
	printf("%d\n",qpow(2,n+m));
	return 0;
}