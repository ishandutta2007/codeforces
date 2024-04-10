#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
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
int a[110],b[110];
void solve(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for (int i=1;i<=n;i++){
		bool flg=1;
		for (int j=1;j<=n;j++){
			if (abs(a[i]-a[j])+abs(b[i]-b[j])<=k);
			else flg=0;
		}
		if (flg){
			printf("1\n"); return;
		}
	}
	puts("-1");
}
int main()
{
	for (int T=read();T--;) solve();
}