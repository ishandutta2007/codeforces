#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<set>
#define N 2020
using namespace std;
int n,minn,ans;
int a[N],b[N];
char ch[N],ss[N];
multiset<int>S;
multiset<int>:: iterator it;
int f[N][N];
bool cmp(int a,int b){return a>b;}
void dp()
{
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			int k=i-j;
			if(j)
			{
				int cnt;if(a[j]>b[i])cnt=1;else cnt=0;
				f[j][k]=max(f[j][k],f[j-1][k]+cnt);
			}
			if(k)
			{
				int cnt;if(a[n-k+1]>b[i])cnt=1;else cnt=0;
				f[j][k]=max(f[j][k],f[j][k-1]+cnt);
			}if(i==n)ans=max(ans,f[j][k]);
		}
}
int main()
{
	scanf("%d",&n);
	scanf("%s%s",ss+1,ch+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=ch[i]-'0';
		S.insert(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=ss[i]-'0';
		it=S.lower_bound(b[i]);
		if(it!=S.end())S.erase(it);
		else minn++;
	}dp();printf("%d %d\n",minn,ans);
}