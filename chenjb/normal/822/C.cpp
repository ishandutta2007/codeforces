#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
struct node
{
	int l,r,len;
	LL cost;
	friend bool operator <(node x,node y)
	{
		return (x.r-x.l+1)<(y.r-y.l+1);
	}
}a[300000];
vector<int> g[300001];
LL f[32][300001];
int save[300001];
int n,target;
LL ans;
bool cmp(int x,int y)
{
	return a[x].l<a[y].l;
}
void make(int len)
{
	if (len<0||len>=300000)return;
	if (g[len].size()==0)return;
	int cnt=g[len].size();
	for(int i=0;i<cnt;i++)save[i]=g[len][i];
	sort(save,save+cnt,cmp);
	for(int i=0;i<cnt;i++)f[0][i]=a[save[i]].cost;
	int tmp=round(log(cnt)/log(2));
	for(int i=1;i<=tmp;i++)
		for(int j=0;j<cnt-(1<<i)+1;j++)
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
}
LL getmin(int l,int r)
{
	int t=log(r-l+1)/log(2);
	return min(f[t][l],f[t][r-(1<<t)+1]);
}
void work()
{
	make(target-a[1].len);
	a[0].len=a[1].len;
	ans=(LL)2147483647*(LL)2147473647;
	LL pre=ans;
	for(int i=1;i<=n;i++)
	{
		if (target<a[i].len)continue;
		if (g[target-a[i].len].size()==0)continue;
		if (a[i].len!=a[i-1].len)make(target-a[i].len);
		int len=target-a[i].len;
		int le=1;
		int ri=g[len].size();
		while (le<ri)
		{
			int mid=(le+ri)/2;
			if (a[save[mid-1]].l<=a[i].r)le=mid+1;
			else ri=mid;
		}
		if (a[save[le-1]].l<=a[i].r)continue;
		LL tmp=getmin(le-1,g[len].size()-1);
		ans=min(ans,tmp+a[i].cost);
	}
	if (ans==pre)cout<<-1<<endl;
	else cout<<ans<<endl;
}
int main()
{
	cin>>n>>target;
	for(int i=0;i<=200010;i++)g[i].clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%i64d",&a[i].l,&a[i].r,&a[i].cost);
		a[i].len=a[i].r-a[i].l+1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)g[a[i].r-a[i].l+1].push_back(i);
	work();
	return 0;
}