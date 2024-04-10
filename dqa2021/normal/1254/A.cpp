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

int T,r,c,k;
char mp[110][110];
char ans[110][110];
char getid(int num)
{
	if (num<=26) return num-1+'a';
	if (num<=52) return num-27+'A';
	return num-53+'0';
}
void init()
{
	
}
void solve()
{
	r=read(),c=read(),k=read();
	int rtot=0;
	for (int i=1;i<=r;i++)
	{
		scanf("%s",mp[i]+1);
		for (int j=1;j<=c;j++)
			if (mp[i][j]=='R')
				rtot++;
	}
	int curid=1,curtot=0;
	for (int i=1;i<=r;i++)
	{
		if (i&1)
		{
			for (int j=1;j<=c;j++)
			{
				ans[i][j]=getid(curid);
				if (mp[i][j]=='R')
				{
					curtot++;
					if (curid!=k&&(curid<=rtot%k&&curtot==rtot/k+1||curid>rtot%k&&curtot==rtot/k)) curid++,curtot=0;
				}
			}
			continue;
		}
		for (int j=c;j;j--)
		{
			ans[i][j]=getid(curid);
			if (mp[i][j]=='R')
			{
				curtot++;
				if (curid!=k&&(curid<=rtot%k&&curtot==rtot/k+1||curid>rtot%k&&curtot==rtot/k)) curid++,curtot=0;
			}
		}
	}
	for (int i=1;i<=r;i++,putchar('\n'))
		for (int j=1;j<=c;j++)
			putchar(ans[i][j]);
}
int main()
{
	for (T=read();T--;) init(),solve();
	return 0;
}