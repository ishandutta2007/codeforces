#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
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
const int U=5e5+5;

char s[500010]; int n;
int c[1000030],d[1000030];
void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=-n-2;i<=n+2;i++) c[U+i]=d[U+i]=0;
	int V=U;
	for (int i=1;i<=n;i++){
		if (s[i]=='1') c[V]++,V++;
		else d[V]++,V--;
	}
	V=U;
	for (int i=1;i<=n;i++){
		if (d[V]&&(!c[V]||c[V-1])) putchar(48),--d[V],V--;
		else putchar(49),--c[V],V++;
	}
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}