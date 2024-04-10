#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n,m,q;
int w1[200010],w2[200010],ww1[200010];
int t[200010],gnd[200010][18],len[200010];
int ans[200010];

int main()
{
	read(n);read(m);read(q);
	for (int i=1;i<=n;i++) read(w1[i]),ww1[w1[i]]=i;
	for (int i=1;i<=m;i++)
	{
		read(w2[i]); w2[i]=ww1[w2[i]];
		int lst=w2[i]-1; if (!lst) lst=n;
		if (t[lst]) gnd[i][0]=t[lst],len[i]=len[t[lst]]+1;
		else len[i]=1;
		t[w2[i]]=i;
		for (int j=1;j<18&&gnd[i][j-1];j++) gnd[i][j]=gnd[gnd[i][j-1]][j-1];
		if (len[i]>=n)
		{
			lst=i;
			for (int j=0;j<18;j++)
			{
				if (((n-1)>>j)&1) lst=gnd[lst][j];
			}
			ans[i]=lst;
		}
		ans[i]=max(ans[i],ans[i-1]);
	}
	int x,y;
	while (q--)
	{
		read(x);read(y);
		putchar(ans[y]>=x?'1':'0');
	}
	putchar('\n');
	return 0;
}