#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
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
ll ans;
int n; char s[300010];
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=3;i<=n;i++)
	{
		int maxr=0;
		for (int a=max(1,i-9);a<=i-2;a++)
			for (int b=a+2;b<=i;b+=2)
			{
				if (s[a]==s[a+b>>1]&&s[a]==s[b]) maxr=max(maxr,a);
			}
		if (maxr) ans+=maxr;
	}
	printf("%I64d\n",ans);
	return 0;
}