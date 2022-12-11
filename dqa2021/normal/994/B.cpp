#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
char ch;
void read(int &x)
{
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for (x=0;ch<='9'&&ch>='0';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
}
int n,m;
ll ans[100010];
priority_queue<int> que;
struct Id{
	int p,c,pos;
}id[100010];
bool cmp(const Id x,const Id y)
{return x.p<y.p;}
int stk[15],top;
int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++) read(id[i].p),id[i].pos=i;
	for (int i=1;i<=n;i++) read(id[i].c);
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		ans[id[i].pos]=id[i].c;
		top=0;
		for (int j=1;j<=m&&!que.empty();j++) stk[++top]=que.top(),ans[id[i].pos]+=stk[top],que.pop();
		for (int j=1;j<=top;j++) que.push(stk[j]);
		que.push(id[i].c);
	}
	for (int i=1;i<=n;i++) printf("%I64d ",ans[i]);
	putchar('\n');
	return 0;
}