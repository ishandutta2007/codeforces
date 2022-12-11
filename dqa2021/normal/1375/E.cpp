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

int n,w[100010],p[100010];
bool cmp(int x,int y){return w[x]<w[y]||w[x]==w[y]&&x<y;}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) w[i]=read(),p[i]=i;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (w[i]>w[j])
				ans++;
	printf("%d\n",ans);
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++) w[p[i]]=i;
	for (int i=1;i<=n;i++){
		static int c[1010],top; top=0;
		for (int j=i+1;j<=n;j++) if (w[i]>w[j]) c[++top]=j;
		sort(c+1,c+top+1,cmp);
		for (int j=top;j;j--) printf("%d %d\n",i,c[j]),swap(w[i],w[c[j]]);
	}
	return 0;
}