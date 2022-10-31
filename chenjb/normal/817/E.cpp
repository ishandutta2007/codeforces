#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
struct node 
{
	int cnt;
	int son[2];
}a[8000000];
int tot,root;
int newnode()
{
	tot++;
	a[tot].cnt=a[tot].son[0]=a[tot].son[1]=0;
	return tot;
}
void insert(int t)
{
	int p=root;
	int tmp;
	for(int i=28;i>=0;i--)
	{
		if (t&(1<<i))tmp=1; else tmp=0;
		if (a[p].son[tmp]==0)a[p].son[tmp]=newnode();
		a[p].cnt++;
		p=a[p].son[tmp];
	}
	a[p].cnt++;
}
void eliminate(int t)
{
	int p=root;
	int tmp;
	for(int i=28;i>=0;i--)
	{
		if (t&(1<<i))tmp=1; else tmp=0;
		a[p].cnt--;
		p=a[p].son[tmp];
	}
	a[p].cnt--;
}
void query(int x,int l)
{
	int ans=0;
	int p=root;
	int tmp,t1,t2;
	for(int i=28;i>=0;i--)
	{
		if (a[p].cnt==0)break;
		if (x&(1<<i))t1=1; else t1=0;
		if (l&(1<<i))t2=1; else t2=0;
		if ((t1^1)==t2)tmp=1; else tmp=0;
		if (t2==1)ans+=a[a[p].son[tmp^1]].cnt;
		p=a[p].son[tmp];
	}
	printf("%d\n",ans);
}
int main()
{
	int q;
	cin>>q;
	tot=-1;
	newnode();
	root=newnode();
	for(int i=1;i<=q;i++)
	{
		int way,p,l;
		scanf("%d",&way);
		if (way==1)
		{
			scanf("%d",&p);
			insert(p);
		}
		if (way==2)
		{
			scanf("%d",&p);
			eliminate(p);
		}
		if (way==3)
		{
			scanf("%d%d",&p,&l);
			query(p,l);
		}
	}
}