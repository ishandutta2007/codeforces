#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
}

int n,w[200010];
int ans;
namespace L
{
	int rec[30],lb[30];
	void ins(int x)
	{
		int y=x;   //caution x changes
		for (int i=17;~i;i--)
			if ((x>>i)&1)
			{
				if (lb[i])
				{
					x^=lb[i]; continue;
				}
				lb[i]=x; rec[++*rec]=y; return;
			}
	}
}
using namespace L;  //caution
int ww[262200];
int main()
{
	read(n); for (int i=1;i<=n;i++) read(w[i]);
	
//	printf("%d\n",n);
//	for (int i=1;i<=n;i++) printf("%d ",w[i]); puts("");   //!!! grader
	
	sort(w+1,w+n+1);
	int pos=1;
	for (int i=0;pos<=n;i++)
	{
		while (pos<=n&&w[pos]<(1<<i)) ins(w[pos]),pos++;
		if ((*rec)==i) ans=i;
	}
	printf("%d\n",ans);
	memset(rec,0,sizeof rec); memset(lb,0,sizeof lb);
	for (pos=1;pos<=n&&w[pos]<(1<<ans);pos++) ins(w[pos]);
//	printf("test %d: %d %d\n",(*rec),rec[1],rec[2]);
	ww[++*ww]=0;
	for (int i=1;i<=ans;i++)
	{
		for (int j=(*ww);j;j--)
			ww[++*ww]=ww[j]^rec[i];
	}
	for (int i=1;i<=(*ww);i++) printf("%d ",ww[i]); puts("");
	return 0;
}