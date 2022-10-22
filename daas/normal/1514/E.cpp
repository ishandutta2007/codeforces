#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=110;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,line[MAXN],mem[MAXN];
int check1(int u,int v)
{
	printf("1 %d %d\n",u-1,v-1);
	fflush(stdout);
	return read();
}
void Get_line(int l,int r)
{
	if(l==r) {line[l]=l;return;}
	int mid=(l+r)>>1;
	Get_line(l,mid);
	Get_line(mid+1,r);
	int bjl=l,bjr=mid+1,bj=l-1;
	while(bjl<=mid || bjr<=r)
	{
		if(bjl<=mid && (bjr>r || check1(line[bjl],line[bjr]))) mem[++bj]=line[bjl++];
		else mem[++bj]=line[bjr++];
	}
	for(int i=l;i<=r;++i) line[i]=mem[i];
}
int head[MAXN],tot;
struct node
{
	int to,nextn;
}a[MAXN*2];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
int pd[MAXN];
void fun(int u,int tim)
{
	pd[u]=tim;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(pd[v]==tim) continue;
		fun(v,tim);
	}
}
int check2(int lim,int x)
{
	printf("2 %d %d",line[x]-1,lim);
	for(int i=1;i<=lim;++i) printf(" %d",line[i]-1);
	putchar('\n');
	fflush(stdout);
	return read();
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		Get_line(1,n);
		memset(head,0,sizeof(head));
		tot=0;
		for(int i=2;i<=n;++i) ADD(line[i-1],line[i]);
		for(int i=n,least=n-1;i>1;--i,least=min(least,i-1))
		{
			int flag=0;
			while(least && check2(least,i)) --least,flag=1;
			if(flag) ADD(line[i],line[least+1]);
		}
		memset(pd,0,sizeof(pd));
		puts("3");
		for(int i=1;i<=n;++i)
		{
			fun(i,i);
			for(int j=1;j<=n;++j)
				if(pd[j]==i) putchar('1');
				else putchar('0');
			putchar('\n');
		}
		fflush(stdout);
		read();
	}
	return 0;
}