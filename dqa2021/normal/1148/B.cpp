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
typedef long long ll;

int n,m,ta,tb,K;
int a[200010],b[200010];
ll ans=-0x7fffffffffffffffLL;
int main()
{
	n=read(),m=read(),ta=read(),tb=read(),K=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	if (K>=n||K>=m) return puts("-1"),0;
	int pos=0;
	for (int i=0;i<=K&&i<=n;i++)
	{
		while (pos<m&&b[pos+1]<a[i+1]+ta) pos++;
		if (pos+1+K-i>m) return puts("-1"),0;
//		printf("find %d and %d\n",i+1,pos+1);
		ans=max(ans,(ll)b[pos+K-i+1]+tb);
//		printf("%I64d\n",ans);
	}
	printf("%I64d\n",ans);
	return 0;
}