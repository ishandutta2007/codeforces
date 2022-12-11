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

int n,w[1<<20];
void solve(){
	n=read();
	for (int i=1;i<=n;i++){
		w[i]=read();
		if (w[i]<0) w[i]=-w[i];
	}
	for (int i=1;i+2<=n;i+=2){
		if (w[i]<w[i+1]&&w[i+1]<w[i+2]||
			w[i]>w[i+1]&&w[i+1]>w[i+2])
				w[i+1]=-w[i+1];
	}
	for (int i=1;i<=n;i++) printf("%d ",w[i]);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}