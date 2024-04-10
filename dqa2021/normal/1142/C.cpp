#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
}
typedef long long ll;

int n;
struct Node{
	int x; ll y;
}node[100010];
bool cmp(Node x,Node y)
{
	if (x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
Node operator-(Node x,Node y)
{
	return (Node){x.x-y.x,x.y-y.y};
}
ll cross(Node x,Node y)
{
	return x.x*y.y-x.y*y.x;
}
int stk[100010];

int main()
{
	read(n);
//	if (n==1){puts("0");return 0;}
	for (int i=1,x,y;i<=n;i++)
	{
		read(x);read(y);
		node[i].x=x; node[i].y=y-(ll)x*x;
//		printf("get %d %lld\n",node[i].x,node[i].y);
	}
	sort(node+1,node+n+1,cmp);
	stk[++*stk]=1;
	for (int i=2;i<=n;i++)
	{
		while ((*stk)>1&&cross(node[stk[*stk]]-node[stk[(*stk)-1]],node[i]-node[stk[*stk]])>=0) (*stk)--;
		stk[++*stk]=i;
	}
	int hd=1,tl=(*stk);
	while (hd<tl&&node[stk[hd]].x==node[stk[hd+1]].x) hd++;
	while (hd<tl&&node[stk[tl]].x==node[stk[tl-1]].x) tl--;
//	for (int i=1;i<=(*stk);i++) printf("find %d %lld\n",node[stk[i]].x,node[stk[i]].y);
	printf("%d\n",tl-hd);  //not hd-tl
	return 0;
}