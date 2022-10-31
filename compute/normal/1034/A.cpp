#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7;
vector<int> prime;
int isp[maxn];
void db()
{
	memset(isp,0,sizeof(isp));
	for(int i=2;i<maxn;i++)
	{
		if(!isp[i]){prime.push_back(i);isp[i]=i;}
		for(int j=0;j<prime.size()&&i*prime[j]<maxn;j++)
		{
			isp[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
}
int arr[maxn/50];
int cnt[maxn];
int main()
{
	db();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int gcd=0;
	for(int i=0;i<n;i++) gcd=__gcd(gcd,arr[i]);
	for(int i=0;i<n;i++) arr[i]/=gcd;
	for(int i=0;i<n;i++)
	{
		int cur=isp[arr[i]];
		while(cur)
		{
			cnt[cur]++;
			while(arr[i]%cur==0)
				arr[i]/=cur;
			cur=isp[arr[i]];
		}
	}
	int ans=0;
	for(int i=0;i<maxn;i++) ans=max(ans,cnt[i]);
	printf("%d\n",ans?n-ans:-1);
}