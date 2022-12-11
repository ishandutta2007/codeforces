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
typedef long long ll;

int n,m,w[100010];
ll tot;
int ans[100010];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++) w[i]=read(),tot+=w[i];
	if (tot<n) return puts("-1"),0;
	for (int i=1;i<=m;i++) if (w[i]+i-1>n) return puts("-1"),0; else ans[i]=i;
	int last=n+1;
	for (int i=m;i;i--){
		if (ans[i]+w[i]-1<last-1) last=ans[i]=last-w[i];
		else last=ans[i];
	}
	if (last!=1) return puts("-1"),0;
	for (int i=1;i<=m;i++) printf("%d ",ans[i]); puts("");
	return 0;
}