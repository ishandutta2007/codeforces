#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int w;
	int num;
	friend bool operator <(node x,node y)
	{
		return x.w>y.w;
	}
}a[200];
int n,w;
int ans[200];
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++){ cin>>a[i].w; a[i].num=i; }
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ans[a[i].num]=(a[i].w+1)/2;
		w-=ans[a[i].num];
	}
	int i=1;
	while (w>0&&i<=n)
	{
		int t=min(w,a[i].w-ans[a[i].num]);
		w-=t;
		ans[a[i].num]+=t;
		i++;
	}
	if (w!=0)cout<<-1<<endl;
	else
	{
		cout<<ans[1];
		for(int i=2;i<=n;i++)cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}