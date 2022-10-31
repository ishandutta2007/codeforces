#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> prime;
int isp[maxn];
int s[maxn];
void add(int n)
{
	isp[n]++;
}
void factor(int n)
{
	int up=sqrt(n);
	for(int i=2;i<=up;i++)
	{
		if(n%i==0) add(i);
		while(n%i==0) n/=i;
	}
	if(n>1) add(n);
}
int main()
{
	memset(isp,0,sizeof(isp));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		factor(s[i]);
	}
	int ans=1;
	for(int i=0;i<maxn;i++)
		ans=max(ans,isp[i]);
	printf("%d\n",ans);
}