#include<bits/stdc++.h>
#define N (int)5e5+1003
using namespace std;
struct node
{
	int l,r,p;
}f[N];
bool F[1000003];
struct Stack
{
	int val[1000003],head;
	void pop()
	{
		head--;
		F[val[head]]=0;
	}
	int top()
	{
		assert(head);
		return val[head-1];
	}
	void push(int x)
	{
		if(F[x]) return;
		F[x]=1;
		val[head++]=x;
	}
	bool empty()
	{
		return !head;
	}
}st;
int n,m,a[N],pos[N],ans[N],sz,bin[N];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
inline bool cmp(const node& x,const node& y)
{
	return pos[x.l]!=pos[y.l]?x.l<y.l:((pos[x.l]&1)?x.r<y.r:x.r>y.r);
}
int main()
{
	n=read();sz=sqrt(n)+3;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<N;i++)pos[i]=i/sz;
	m=read();
	for(int i=1;i<=m;i++)f[i].l=read(),f[i].r=read(),f[i].p=i;
	sort(f+1,f+1+m,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(f[i].l<l)
		{
			if(++bin[a[--l]]==1)st.push(a[l]);
//			debug();
		}
		while(f[i].r>r)
		{
			if(++bin[a[++r]]==1)st.push(a[r]);
//			debug();
		}
		while(f[i].l>l)
		{
			if(--bin[a[l]]==1)st.push(a[l]);l++;
//			debug();
		}
		while(f[i].r<r)
		{
			if(--bin[a[r]]==1)st.push(a[r]);r--;
//			debug();
		}
		while(!st.empty())
		{
			if(bin[st.top()]==1)
			{
				ans[f[i].p]=st.top();
				break;
			}
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}