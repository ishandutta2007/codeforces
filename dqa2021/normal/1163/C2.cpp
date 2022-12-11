#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
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
const double eps=1e-10;

int n;
struct Node{
	int x,y;
}node[1010];
struct L{
	bool id;   //y=kx+b x=k
	double k,b;
}l[1000010];  //l used
int idtot;
bool operator<(L x,L y)
{
	if (x.id!=y.id) return x.id>y.id;
	if (x.id)
	{
		return x.k+eps<y.k;
	}
	if (x.k!=y.k) return x.k+eps<y.k;
	return x.b+eps<y.b;
}
typedef long long ll;
ll ans;  //%I64d
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		node[i].x=read(); node[i].y=read();
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (node[i].x==node[j].x) l[++idtot]=(L){1,node[i].x,0};
			else l[++idtot]=(L){0,(double)(node[i].y-node[j].y)/(node[i].x-node[j].x),0},l[idtot].b=node[i].y-l[idtot].k*node[i].x;
		}
//	for (int i=1;i<=idtot;i++)
//		if (!l[i].id) printf("y=%.5lfx+%.5lf\n",l[i].k,l[i].b);
//		else printf("x=%.5lf\n",l[i].k);
//	puts("end");
	sort(l+1,l+idtot+1);
//	for (int i=1;i<=idtot;i++)
//		if (!l[i].id) printf("y=%.5lfx+%.5lf\n",l[i].k,l[i].b);
//		else printf("x=%.5lf\n",l[i].k);
	int tmp=0;
	for (int i=1;i<=idtot;i++)
	{
		if (i==1||((l[i-1]<l[i])||(l[i]<l[i-1]))) l[++tmp]=l[i];
	}
	idtot=tmp;
	int pos=1;
	if (l[1].id)
	{
		while (pos<=idtot&&l[pos].id) pos++;
		ans+=(ll)(pos-1)*(idtot-pos+1);
	}
	for (;pos<=idtot;)
	{
		int i=pos;
		while (pos<=idtot&&fabs(l[pos].k-l[i].k)<eps) pos++;
		ans+=(ll)(pos-i)*(idtot-pos+1);
	}
	printf("%I64d\n",ans);
	return 0;
}