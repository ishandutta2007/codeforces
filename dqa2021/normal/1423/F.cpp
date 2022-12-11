#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

int n,k;
int a[200010],b[200010];
ll S;
int main()
{
	n=read(),k=read();
	for (int i=1;i<=k;i++){
		a[i]=read(),b[i]=read();
		S+=b[i];
	}
	if (S>n) return puts("-1"),0;
	if (S<n) return puts("1"),0;
	S=0;
	for (int i=1;i<=k;i++) S+=1LL*a[i]*b[i];
	puts(S%n != (n-1LL)*n/2%n? "-1":"1");
	return 0;
}