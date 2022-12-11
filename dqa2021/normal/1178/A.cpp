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

int n,w[110];
int totok,oktot;
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		w[i]=read(),w[0]+=w[i];
		if (i==1||w[i]*2<=w[1]) totok+=w[i],oktot++;
	}
	if (totok>w[0]/2)
	{
		printf("%d\n",oktot);
		for (int i=1;i<=n;i++)
		{
//			w[i]=read();
			if (i==1||w[i]*2<=w[1]) printf("%d ",i);
		}
		puts("");
	}
	else puts("0");
	return 0;
}