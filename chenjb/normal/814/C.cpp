#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#define LL long long 
using namespace std;
vector<int> g[30];
int n,q;
char a[2000];
int sum[30][2000];
int ans[30][2000];
int work(int p,int ti)
{
	int cnt=g[p].size();
	ti=min(ti,n-cnt);
	int ans=ti;
	for(int i=0;i<cnt;i++)
	{
		int le=g[p][i];
		int ri=n;
		while (le<ri)
		{
			int mid=(le+ri)/2 + 1;
			if ((mid-g[p][i]+1)-(sum[p][mid]-sum[p][g[p][i]-1])>ti)ri=mid-1;
			else le=mid;
		}
		int used=(le-g[p][i]+1)-(sum[p][le]-sum[p][g[p][i]-1]);
		ans=max(ans,le-g[p][i]+1+ti-used);
	}
	return ans;
}
int main()
{	
	cin>>n;
	for(int i=1;i<=26;i++)g[i].clear();
	getchar();
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
		a[i]=getchar();
		g[a[i]-'a'+1].push_back(i);
		sum[a[i]-'a'+1][i]=1;
	}
	for(int i=1;i<=26;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]+=sum[i][j-1];
	cin>>q;
	for(int i=1;i<=26;i++)
		for(int j=0;j<=n;j++)
			ans[i][j]=work(i,j);
	for(int i=1;i<=q;i++)
	{
		int ti;
		char c;
		scanf("%d %c",&ti,&c);
		int cnt=g[c-'a'+1].size();
		ti=min(ti,n-cnt);
		cout<<ans[c-'a'+1][ti]<<endl;
	}
}