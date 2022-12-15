#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,k,a[N],c[N],cnt[N];
vector<int> G[N];
bool cmp(int x,int y){return x>y;}
inline bool check(int x)
{
	for(int i=1;i<=x;i++)cnt[i]=0;
	int pos=0;
	for(int i=1;i<=n;i++)
	{	
		pos++;
		if(pos>x)pos=1;
		int j=pos;
		while(cnt[pos]>=c[a[i]] && j!=pos){pos++;if(pos>x)pos=1;}
		if(cnt[pos]<c[a[i]])cnt[pos]++;
		else return 0;
	}
	return 1;
}
inline void print(int x)
{
	printf("%d\n",x);
	for(int i=1;i<=x;i++)cnt[i]=0;
	int pos=0;
	for(int i=1;i<=n;i++)
	{	
		pos++;
		if(pos>x)pos=1;
		int j=pos;
		while(cnt[pos]>=c[a[i]] && j!=pos){pos++;if(pos>x)pos=1;}
		if(cnt[pos]<c[a[i]])cnt[pos]++,G[pos].push_back(a[i]);
	}
	for(int i=1;i<=x;i++)
	{
		printf("%d ",G[i].size());
		for(int j=0;j<G[i].size();j++)printf("%d ",G[i][j]);
		putchar('\n');
	}
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=k;i++)c[i]=read();
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	print(l);
	return 0;
}