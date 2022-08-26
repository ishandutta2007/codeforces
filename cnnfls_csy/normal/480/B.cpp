#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,x,y,i,j,num[100005];
pair<int,int> findfi(int x)
{
	int l=1,r=1;
	for (r=1;r<=n;r++)
	{
		while (num[l]+x<num[r]&&l<=n) l++;
		if (num[l]+x==num[r]) return {num[l],num[r]};
	}
	return {-1,-1};
}
pair<int,int> findls(int x)
{
	int l=n,r=n;
	for (l=n;l;l--)
	{
		while (num[l]+x<num[r]&&r>=1) r--;
		if (num[l]+x==num[r]) return {num[l],num[r]};
	}
	return {-1,-1};
}
bool in(long long x)
{
	return (x>-1&&x<=m);
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>x>>y;
	for (i=1;i<=n;i++) cin>>num[i];
	if (findfi(x)!=pair<int,int>{-1,-1})
	{
		if (findfi(y)!=pair<int,int>{-1,-1})
		{
			cout<<0;
			return 0;
		}
		cout<<1<<endl<<y;
		return 0;
	}
	if (findfi(y)!=pair<int,int>{-1,-1})
	{
		cout<<1<<endl<<x;
		return 0;
	}
	if (findfi(x+y)!=pair<int,int>{-1,-1})
	{
		cout<<1<<endl<<findfi(x+y).first+x;
		return 0;
	}
	//if (x<y) swap(x,y);
	if (findfi(y-x)!=pair<int,int>{-1,-1}&&findfi(y-x).first+y<=m)
	{
		cout<<1<<endl<<findfi(y-x).first+y;
		return 0;
	}
	if (findls(y-x)!=pair<int,int>{-1,-1}&&findls(y-x).first-x>=0)
	{
		cout<<1<<endl<<findls(y-x).first-x;
		return 0;
	}
	cout<<2<<endl<<x<<' '<<y;
	return 0;
}