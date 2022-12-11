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

int n;
int c[20],cc[20];
int ans;
int main()
{
	n=read();
	for (int u=1,x;u<=n;u++)
	{
		x=read();
		c[x]++;
		memcpy(cc,c,sizeof c);
		sort(cc+1,cc+11);
		int pos;
		for (pos=1;!cc[pos];pos++);
		for (int i=pos;i<=10;i++)
		{
			cc[i]--;
			int minn=0x7fffffff,maxn=-0x7fffffff;
			for (int j=pos;j<=10;j++)
			{
				if (!cc[j]) continue;
				minn=min(minn,cc[j]); maxn=max(maxn,cc[j]);
			}
			if (minn==0x7fffffff&&maxn==-0x7fffffff||minn==maxn){ans=u;break;}
			cc[i]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}