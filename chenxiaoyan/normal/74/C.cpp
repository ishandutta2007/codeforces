#include<iostream>
using namespace std;
int n,m,fat[4000010];
int id(int x,int y)
{
	if(x==1)
		return y;
	if(y==1)
		return m+x-1;
	if(y==m)
		return m+n-1+x-1;
	return m+n-1+n-1+y-1;
}
int ance(int a)
{
	if(fat[a]==a)
		return a;
	return fat[a]=ance(fat[a]);
}
void merge(int a,int b)
{
	fat[ance(a)]=ance(b);
}
int main()
{
	int i,tot=0;
	cin>>n>>m;
	if(n>m)
		swap(n,m);
	for(i=1;i<=m;i++)
		fat[id(1,i)]=id(1,i);
	for(i=2;i<=n;i++)
	{
		fat[id(i,1)]=id(i,1);
		fat[id(i,m)]=id(i,m);
	}
	for(i=2;i<m;i++)
		fat[id(n,i)]=id(n,i);
	// 
	for(i=1;i<=m;i++)
	{
		int x=1,y=i,mn,xn,yn;
		mn=min(n-x,y-1);
		xn=x+mn;
		yn=y-mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
		mn=min(n-x,m-y);
		xn=x+mn;
		yn=y+mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
	}
	for(i=2;i<=n;i++)
	{
		int x,y,mn,xn,yn;
		/////////////////////////////////////////////////////////////////////
		x=i;
		y=1;
		mn=min(x-1,m-y);
		xn=x-mn;
		yn=y+mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
		mn=min(n-x,m-y);
		xn=x+mn;
		yn=y+mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
		/////////////////////////////////////////////////////////////////////
		x=i;
		y=m;
		mn=min(x-1,y-1);
		xn=x-mn;
		yn=y-mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
		mn=min(n-x,y-1);
		xn=x+mn;
		yn=y-mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
	}
	for(i=2;i<=m;i++)
	{
		int x=n,y=i,mn,xn,yn;
		mn=min(x-1,y-1);
		xn=x-mn;
		yn=y-mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
		mn=min(x-1,m-y);
		xn=x-mn;
		yn=y+mn;
		if(ance(id(x,y))!=ance(id(xn,yn)))
			merge(id(x,y),id(xn,yn));
	}
	// 
	for(i=1;i<=m;i++)
		tot+=fat[id(1,i)]==id(1,i);
	for(i=2;i<=n;i++)
	{
		tot+=fat[id(i,1)]==id(i,1);
		tot+=fat[id(i,m)]==id(i,m);
	}
	for(i=2;i<m;i++)
		tot+=fat[id(n,i)]==id(n,i);
	cout<<tot;
	return 0;
}
/*1
3 4
*/
/*2
3 3
*/