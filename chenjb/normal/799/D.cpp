#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
LL  a,b,h,w;
int tot,n,ans;
int tmp[110000];
int aa[110000],bb[110000];
LL mul[110000];
LL pw(int k,LL x)
{
	if (k==0)return 1;
	if (k==1)return x;
	LL t=pw(k/2,x);
	LL ans=t*t;
	if (k%2==1)ans*=x;
	return ans;
}
void dfs(int dep,LL now1,LL now2,int cnt)
{
	if (cnt>ans)return;
	if (now1>=a&&now2>=b)
	{
		ans=min(ans,cnt);
		return;
	}
	if (dep>tot)return;
	for(int i=0;i<=bb[dep];i++)
		for(int j=0;j<=bb[dep]-i;j++)
			dfs(dep+1,now1*pw(i,aa[dep]),now2*pw(j,aa[dep]),cnt+i+j);
}
int main()
{
	cin>>a>>b>>h>>w>>n; 
	for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			tmp[x]++;
			tmp[x]=min(tmp[x],40);
		}

	tot=0;
	for(int i=100000;i>=2;i--)
		if (tmp[i]!=0)aa[++tot]=i,bb[tot]=tmp[i];
	ans=2147483647;
	dfs(1,h,w,0);
	swap(a,b);
	dfs(1,h,w,0);
	if (ans>n)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}