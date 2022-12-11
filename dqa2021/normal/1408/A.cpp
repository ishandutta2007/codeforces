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
	return flg?-x:x;
}
#undef G

int n,a[110],b[110],c[110],p[110];
void init(){
	
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) c[i]=read();
	p[1]=a[1];
	for (int i=2;i<n;i++){
		if (a[i]!=p[i-1]) p[i]=a[i];
		else if (b[i]!=p[i-1]) p[i]=b[i];
		else p[i]=c[i];
	}
	if (a[n]!=p[n-1]&&a[n]!=p[1]) p[n]=a[n];
	else if (b[n]!=p[n-1]&&b[n]!=p[1]) p[n]=b[n];
	else p[n]=c[n];
	for (int i=1;i<=n;i++) printf("%d ",p[i]);
	puts("");
}
int main()
{
	for (int T=read();T--;) init(),solve();
}