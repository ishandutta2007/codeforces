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

int n; char s[300010];
char t[300010];
int ans,anspos1=1,anspos2=1,fstans;
int main()
{
	scanf("%d%s",&n,s+1);
	int totl=0,totr=0;
	for (int i=1;i<=n;i++)
		totl+=(s[i]=='('),
		totr+=(s[i]==')');
	if (totl^totr) return puts("0\n1 1"),0;
	int lastpos=0,top=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='(') top++;
		else if (top) top--;
		else lastpos=i;
	}
//	if (lastpos==-1)
//	{
//		for (int i=1;i<=n;i++) t[i]=s[i];
//	}
//	else
//	{
		int tmp=0;
		for (int i=lastpos+1;i<=n;i++) t[++tmp]=s[i];
		for (int i=1;i<=lastpos;i++) t[++tmp]=s[i];
//	}
	//printf("lastpos %d\n",lastpos);
	//puts(t+1);
	top=0;
	for (int i=1;i<=n;i++)
	{
		if (t[i]=='(') top++;
		else
		{
			top--;
			if (!top) ans++;
		}
	}
	fstans=ans;
	for (int i=1,j;i<=n;i=j+1)
	{
		for (j=i+1,top=1,tmp=0;top;j++)
			if (t[j]=='(') top++;
			else
			{
				top--;
				if (top==1) tmp++;
			}
		j--;
		if (ans<tmp+1)
		{
			//printf("getans %d: %d %d\n",ans,i,j);
			ans=tmp+1,anspos1=(i+lastpos-1)%n+1,anspos2=(j+lastpos-1)%n+1;
		}
		top=0; tmp=0;
		for (int u=i+1,stpos=i+1;u<j;u++)
		{
			if (t[u]=='(') top++;
			else
			{
				top--;
				if (top==1) tmp++;
				else if (!top)
				{
					if (ans<fstans+tmp+1)
					{
						ans=fstans+tmp+1,anspos1=(stpos+lastpos-1)%n+1,anspos2=(u+lastpos-1)%n+1;
					}
					stpos=u+1;
					tmp=0;
				}
			}
		}
	}
	printf("%d\n%d %d\n",ans,anspos1,anspos2);
//	printf("%d\n",ans);
	return 0;
}