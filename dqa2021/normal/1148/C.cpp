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

int n,w[300010],nw[300010];
void doit(int x,int y)
{
	swap(w[x],w[y]);
	swap(nw[w[x]],nw[w[y]]);
}
int a[1500010],b[1500010],tp;
int main()
{
	n=read();
//	printf("%d\n",n);  //debug
	for (int i=1;i<=n;i++) w[i]=read(),nw[w[i]]=i;
//	for (int i=1;i<=n;i++) printf("%d ",w[i]); puts("");  //debug
	for (int i=1;i<n;i++)
	{
//		for (int j=1;j<=n;j++) printf("%d ",w[j]); puts("");  //debug
//		for (int j=1;j<=n;j++) printf("%d ",nw[j]); puts("");  //debug
		if (nw[i]==i) continue;
//		printf("%d and %d\n",i,nw[i]);
		int tmp=nw[i];
		if (nw[i]-i>=(n>>1))
		{
//			puts("A");
			a[++tp]=tmp; b[tp]=i;
			doit(i,tmp);
			continue;
		}
		if (nw[i]<=(n>>1))
		{
//			puts("B");
			a[++tp]=tmp,b[tp]=n; doit(tmp,n);
			a[++tp]=i,b[tp]=n; doit(i,n);
			continue;
		}
		if (i>(n>>1))
		{
//			puts("C");
			a[++tp]=tmp,b[tp]=1; doit(tmp,1);
			a[++tp]=i,b[tp]=1; doit(i,1);
			a[++tp]=tmp,b[tp]=1; doit(tmp,1);
			continue;
		}
//		puts("D");
		a[++tp]=tmp,b[tp]=1; doit(tmp,1);
		a[++tp]=1,b[tp]=n; doit(1,n);
		a[++tp]=n,b[tp]=i; doit(n,i);
		a[++tp]=tmp,b[tp]=1; doit(tmp,1);
	}
	printf("%d\n",tp);
	for (int i=1;i<=tp;i++) printf("%d %d\n",a[i],b[i]);
	return 0;
}