#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#define LL long long
using namespace std;
struct node
{
	int p,t,id;
	friend bool operator <(node x,node y)
	{
		if (x.t-x.p!=y.t-y.p)return x.t-x.p<y.t-y.p;
		else return x.p<y.p;
	}
	int jww()
	{
		return t-p;
	}
}a[110000],b[110000];
int n,w,h;
int tot1,tot2;
queue<int> Q;
int ansx[110000],ansy[110000];
void fuck(int l1,int r1,int l2,int r2)
{
	while (!Q.empty())Q.pop();
	for(int i=r2;i>=l2;i--)Q.push(b[i].id);
	for(int i=l1;i<=r1;i++)
	{
		int x=Q.front();
		Q.pop();
		ansx[x]=a[i].p;
		ansy[x]=h;
		Q.push(a[i].id);
	}
	for(int i=r2;i>=l2;i--)
	{
		int x=Q.front();
		Q.pop();
		ansx[x]=w;
		ansy[x]=b[i].p;
	}
}
int getright1(int x)
{
	int t=x;
	while (t<=tot1&&a[t].jww()==a[x].jww())t++;
	t--;
	return t;
}
int getright2(int x)
{
	int t=x;
	while (t<=tot2&&b[t].jww()==b[x].jww())t++;
	t--;
	return t;
}
int main()
{
	scanf("%d%d%d",&n,&w,&h);
	tot1=tot2=0;
	for(int i=1;i<=n;i++)
	{
		int g,p,t;
		scanf("%d%d%d",&g,&p,&t);
		if (g==1){ tot1++; a[tot1].p=p; a[tot1].t=t; a[tot1].id=i; }
		if (g==2){ tot2++; b[tot2].p=p; b[tot2].t=t; b[tot2].id=i; }
	}
	sort(a+1,a+tot1+1);
	sort(b+1,b+tot2+1);
	int now1,now2;
	now1=now2=1;
	while (now1<=tot1||now2<=tot2)
	{
		if (now1<=tot1&&now2<=tot2&&a[now1].jww()==b[now2].jww())
		{
			int t1=getright1(now1);
			int t2=getright2(now2);
			fuck(now1,t1,now2,t2);
			now1=t1+1;
			now2=t2+1;
		}
		else
		if ((now1<=tot1&&now2<=tot2&&a[now1].jww()<b[now2].jww())||now2>tot2)
		{
			ansx[a[now1].id]=a[now1].p;
			ansy[a[now1].id]=h;
			now1++;
		}
		else
		{
			ansx[b[now2].id]=w;
			ansy[b[now2].id]=b[now2].p;
			now2++;
		}
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",ansx[i],ansy[i]);
}