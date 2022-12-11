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

int n;
char s[100];
int c[100];
int ans;
int main()
{
	n=read();
	while (n--) scanf("%s",s),c[s[0]-'a']++;
	for (int i=0;i<26;i++)
	{
		int a=c[i]/2; int b=c[i]-a;
		ans+=a*(a-1)/2+b*(b-1)/2;
	}
	printf("%d\n",ans);
	return 0;
}