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
	if (!flg) return x; return -x;
}
typedef long long ll;
ll ans;

char s[1000010]; int len;
int rtot[1000010],ltot;
int main()
{
	scanf("%s",s+1); len=strlen(s+1);
	for (int i=len-1;i;i--)
	{
		rtot[i]=rtot[i+1]+(s[i]=='v'&&s[i+1]=='v');
	}
	for (int i=2;i<len;i++)
	{
		if (s[i]=='v'&&s[i-1]=='v') ltot++;
		if (s[i]=='o') ans+=(ll)ltot*rtot[i+1];
	}
	printf("%I64d\n",ans);
	return 0;
}