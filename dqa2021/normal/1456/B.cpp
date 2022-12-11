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

int n,a[200010],b[200010],c[200010];
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),c[i]=c[i-1]^a[i];
	for (int i=1;i<=n;i++){
		for (int j=29;j>=0;j--)
			if (a[i]>>j&1){
				b[i]=j; break;
			}
	}
	for (int i=1;i+2<=n;i++){
		if (b[i]==b[i+1]&&b[i+1]==b[i+2]) return printf("%d\n",1),0;
	}
	int ans=1e9;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=i;k<j;k++)
				if ((c[k]^c[i-1])>(c[j]^c[k]))
					ans=min(ans,j-i-1);
	if (ans==1e9) puts("-1");
	else printf("%d\n",ans);
	return 0;
}