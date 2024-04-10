#include<cstdio>
#include<iostream>
#include<climits>
#include<vector>
#include<set> 
#include<algorithm>
#define N 850000
int n,k,q,t[N],l,r,c[210000];
using namespace std;
inline int read()
{
	unsigned ret=0; char c=getchar();
	while(c>57 || c<48) c=getchar();
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
inline void ins(int p, int l, int r, int x, int y)  //const  &
{
	if(l>=x && r<=y) //==
	{
		++t[p];
		return;
	}
	if(p==0)
	int ooo=5;
	int mid=(l+r)>>1;
	if(x>mid)ins(p*2+1,mid+1,r,x,y);
	else if(y<=mid)ins(p*2,l,mid,x,y);
	else 
	{ins(p*2+1,mid+1,r,mid+1,y),ins(p*2,l,mid,x,mid);}// {}
}

inline int qq(int p, int l, int r, int x)  //const  &  //,y=0
{
	int ans=t[p]; 
	if(ans>0)
	int wqy=555;
	if(l==r)return ans; //t[p]
	int mid=(l+r)>>1;
	if(x>mid)return ans+qq(p*2+1,mid+1,r,x);
	return ans+qq(p*2,l,mid,x);
}

int main()
{
	n=read(); k=read(); q=read();
	for(int i=1; i<=n; ++i)
	{
		l=read(),r=read();
		ins(1,1,200000,l,r);
	}
	for(int i=1; i<=200000; ++i)if(qq(1,1,200000,i)>=k)c[i]=1; //x  qunajv   //l,r  yuchuli
	for(int i=1; i<=200000; ++i)c[i]+=c[i-1];
	while(q--)
	{
		l=read(),r=read();
		printf("%d\n",c[r]-c[l-1]);
	}
}