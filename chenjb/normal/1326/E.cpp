#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
#define inf 998244353
#define maxn 310000
using namespace std;
int n;
int p[maxn],q[maxn],pos[maxn];
struct node
{
	int max,p;
}st[maxn*5];
void clear(int t)
{
	st[2*t].max+=st[t].p;
	st[2*t+1].max+=st[t].p;
	st[2*t].p+=st[t].p;
	st[2*t+1].p+=st[t].p;
	st[t].p=0;
}
void modify(int t,int l,int r,int a,int b,int k)
{
	if (a<=l && r<=b)
	{
		st[t].max+=k;
		st[t].p+=k;
		return;
	}
	if (st[t].p)clear(t);
	int mid=(l+r)/2;
	if (a<=mid)modify(2*t,l,mid,a,b,k);
	if (b>mid)modify(2*t+1,mid+1,r,a,b,k);
	st[t].max=max(st[2*t].max,st[2*t+1].max);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	int nowans=n;
	modify(1,1,n,1,pos[n],1);
	//cout<<st[1].max<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",nowans);
		modify(1,1,n,1,q[i],-1);
		//cout<<i<<endl;
		//cout<<pos[q[i]]<<" "<<n<<" "<<st[1].max<<endl;
		while (st[1].max<=0 && nowans>1)
		{
			nowans--;
			modify(1,1,n,1,pos[nowans],1);
		}
	}
	puts("");
	return 0;
}