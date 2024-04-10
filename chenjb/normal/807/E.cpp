#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
int pow2[50],rest[50];
int one,maxpow,n;
int ans[110000],tot;

int judge(int num)
{
	int left=0;
	int now=min(num,pow2[0]);
	if (num<pow2[0])left=pow2[0]-num;
	for(int i=1;i<=maxpow;i++)	
	{
		if (now<=pow2[i])left=left+(pow2[i]-now);
		else 
		{
			left=max(left-(now-pow2[i]),0);
			now=pow2[i];
		}
		left=left+rest[i];
	}
	if (left>now)return 0;
	for(int i=maxpow+1;i<=49;i++)if (rest[i]!=0)return 0;
	return 1;
}

int main()
{
	//freopen("1.in","r",stdin);
	cin>>n;
	memset(pow2,0,sizeof(pow2));
	memset(rest,0,sizeof(rest));
	one=0;
	LL x;
	maxpow=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if (x==1)one++;
		LL p=x;
		int cnt=0;
		while (x%2==0)cnt++,x/=2;
		maxpow=max(maxpow,cnt);
		if (x==1)pow2[cnt]++;
		else
		{
			int cnt=0;
			LL t=1;
			while (t<=p)cnt++,t*=2;
			rest[cnt-1]++;
		}
	}

	tot=0;
	for(int i=1;i<=one;i++)
		if (judge(i))ans[++tot]=i;
	if (tot==0)cout<<-1<<endl;
	else
	{
		for(int i=1;i<tot;i++)cout<<ans[i]<<" ";
		cout<<ans[tot]<<endl;
	}
	return 0;
}