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

int n,p[300010];
int stk[300010],top;
void solve(){
	n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	stk[top=1]=p[1];
	for (int i=2;i<=n;i++){
		if (stk[top]>p[i]){stk[++top]=p[i]; continue;}
		while (top&&stk[top]<p[i]) top--;
		top++;
	}
	puts(top==1?"YES":"NO");
}
int main()
{
	for (int T=read();T--;) solve();
}