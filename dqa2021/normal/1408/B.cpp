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

int n,k;
int a[110];
void init(){
	
}
void solve(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n;i;i--) a[i]=a[i]-a[i-1];
	int t=0;
	for (int i=2;i<=n;i++) t+=a[i]!=0;
	if (k==1){
		if (t==0) puts("1");
		else puts("-1");
	}
	else{
		printf("%d\n",max(1,(t+k-2)/(k-1)));
	}
}
int main()
{
	for (int T=read();T--;) init(),solve();
}