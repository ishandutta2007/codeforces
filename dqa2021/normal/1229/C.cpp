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
typedef long long ll;

int n,m,q;
struct Edge{
	int to,nxt;
}edge[100010];
int last[100010];
ll ans; int din[100010],dout[100010];
int main()
{
	n=read(),m=read();
	for (int i=1,x,y;i<=m;i++)
	{
		x=read(),y=read();
		if (x<y) edge[i]=(Edge){y,last[x]},last[x]=i,din[x]++,dout[y]++;
		else edge[i]=(Edge){x,last[y]},last[y]=i,din[y]++,dout[x]++;
	}
	for (int i=1;i<=n;i++) ans+=1LL*din[i]*dout[i];
	printf("%I64d\n",ans);   //I64d !!!
	q=read();
	while (q--)
	{
		int x=read();
		ans-=1LL*din[x]*dout[x];
		for (int &i=last[x],a,b;i;i=b)
		{
			a=edge[i].to,b=edge[i].nxt;
			ans-=1LL*din[a]*dout[a];
			din[x]--,dout[x]++,din[a]++,dout[a]--;
			ans+=1LL*din[a]*dout[a];
			edge[i]=(Edge){x,last[a]},last[a]=i;
		}
		ans+=1LL*din[x]*dout[x];
		printf("%I64d\n",ans);
	}
	return 0;
}