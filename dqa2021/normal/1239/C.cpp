#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
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

int n,p,t[100010];
struct Node{
	ll t; int opt,id;
};
bool operator<(const Node x,const Node y)
{
	if (x.t^y.t) return x.t>y.t;
	if (x.opt^y.opt) return x.opt<y.opt;
	return x.id>y.id;
}
priority_queue<Node> que1;
int que2[100010],hd,tl;
priority_queue<int,vector<int>,greater<int> > que3;
ll ans[100010];
int main()
{
	n=read(); p=read();  //p used
	for (int i=1;i<=n;i++)
	{
		t[i]=read();
		que1.push((Node){t[i],1,i});
	}
	while (!que1.empty())
	{
		Node cur=que1.top(); que1.pop();
		if (cur.opt==0)
		{
			hd++;
			if (!que3.empty()&&que3.top()<(hd<tl?que2[tl]:0x7fffffff))
			{
				que2[++tl]=que3.top(); que3.pop();
			}
			if (hd<tl)
			{
				ans[que2[hd+1]]=cur.t+p;
				que1.push((Node){cur.t+p,0,que2[hd+1]});
			}
			continue;
		}
		if (cur.id<(hd<tl?que2[tl]:0x7fffffff))
		{
			que2[++tl]=cur.id;
			if (hd+1==tl) ans[cur.id]=cur.t+p,que1.push((Node){cur.t+p,0,cur.id});
		}
		else
		{
			que3.push(cur.id);
		}
	}
	for (int i=1;i<=n;i++) printf("%I64d ",ans[i]); putchar('\n');  //I64d!!!
	return 0;
}