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

int n,p[400010];
void init()
{
	
}
void solve()
{
	n=read(); for (int i=1;i<=n;i++) p[i]=read();
	int a=1; while (a<n&&p[a+1]==p[a]) a++;
	int b=a+a+1; while (b<n&&p[b+1]==p[b]) b++;
	int c=b+a+1; while (c<n&&p[c+1]==p[c]) c++;
	if (b>n||c>n) return puts("0 0 0"),void();
	if (c*2>n) return puts("0 0 0"),void();
	int ans=c; for (c++;c<=n;c++) if ((c==n||p[c+1]!=p[c])&&(c<<1)<=n) ans=c;
	printf("%d %d %d\n",a,b-a,ans-b);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}