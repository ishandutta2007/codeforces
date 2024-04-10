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
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int inf[3]={998244353,100000007,995344853};
struct node 
{ 
	int l1,l2,len; 
}a[200010];
int l1[200010],l2[200010],len[200020];
long long f1[200010],f2[200010],base[200010];
int sum[200010],nxt[200010],n,m,tt;
char s[200010];
long long ans[200010];

void work(int ti)
{
	base[0]=1;
	rep(i,200000)base[i]=base[i-1]*37%inf[ti];

	int tot=0;
	rep(i,n)sum[i]=sum[i-1]+(s[i]=='0');
	rep(i,n)
	if (s[i]=='0')
	{
		tot++;
		if (i&1)
		{
			f1[tot]=(f1[tot-1]*37+1)%inf[ti];
			f2[tot]=(f2[tot-1]*37+2)%inf[ti];
		}
		else 
		{
			f1[tot]=(f1[tot-1]*37+2)%inf[ti];
			f2[tot]=(f2[tot-1]*37+1)%inf[ti];
		}
	}
	nxt[n+1]=n+1;

	for (int i=n;i;i--)
		if (s[i]=='0')nxt[i]=i;
		else nxt[i]=nxt[i+1];

	rep(i,m)
	{
		int x1=l1[i];
		int y1=l1[i]+len[i]-1;
		int x2=l2[i];
		int y2=l2[i]+len[i]-1;
		if (sum[y1]-sum[x1-1]!=sum[y2]-sum[x2-1]){ ans[i]=1;continue; }
		if (sum[y1]==sum[x1-1]) continue;
		int tlen=sum[y1]-sum[x1-1];
		if ((x1&1)==(x2&1))
		{
			long long t1=((f1[sum[y1]]-f1[sum[x1-1]]*base[tlen]%inf[ti])%inf[ti]+inf[ti])%inf[ti];
			long long t2=((f1[sum[y2]]-f1[sum[x2-1]]*base[tlen]%inf[ti])%inf[ti]+inf[ti])%inf[ti];
			if (t1!=t2)ans[i]=1;
		}
		else
		{
			long long t1=((f1[sum[y1]]-f1[sum[x1-1]]*base[tlen]%inf[ti])%inf[ti]+inf[ti])%inf[ti];
			long long t2=((f2[sum[y2]]-f2[sum[x2-1]]*base[tlen]%inf[ti])%inf[ti]+inf[ti])%inf[ti];
			if (t1!=t2)ans[i]=1;
		}
	}
}

int main()
{

	cin>>n;
	scanf("%s",s+1);
	cin>>m;
	for (int i=1;i<=m;i++)scanf("%d%d%d",&l1[i],&l2[i],&len[i]);;
	work(0); work(1); work(2);
	for (int i=1;i<=m;i++) 
		if (!ans[i])puts("Yes"); else puts("No");
	return 0;
}