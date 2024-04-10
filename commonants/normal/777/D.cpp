#include<bits/stdc++.h>
#define N 500020
#define inf 1<<28
using namespace std;
typedef unsigned long long ll;
vector<int>mp[N];
vector<ll>hash[N];
int f[2][N],ans;
const ll sed=173;
int n,lim[N],len[N];
int mn[N];
char ch[N];
int solve(int u)
{
	int l=0,r=min(len[u],len[u+1]),ret=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(hash[u][mid]==hash[u+1][mid])
			l=mid+1,ret=mid;
		else r=mid-1;
	}return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		len[i]=strlen(ch)-1;
		mp[i].push_back(0);
		hash[i].push_back(0);
		ll tmp=0;
		for(int j=1;j<=len[i];j++)
		{
			int c=ch[j]-'a'+1;
			mp[i].push_back(c);
			tmp=tmp*sed+c;
			hash[i].push_back(tmp);
		}
	}
	for(int i=n-1;i;i--)
	{
		int x=solve(i);
		int minn=min(len[i],len[i+1]);
		if(x==minn)lim[i]=x;
		else
		{
			if(mp[i][x+1]<mp[i+1][x+1])
				lim[i]=len[i];
			else lim[i]=x;
		}len[i]=lim[i];
	}lim[n]=len[n];
	for(int i=1;i<=n;i++)
	{
		putchar('#');
		for(int j=1;j<=lim[i];j++)
		{
			int c=mp[i][j]+'a'-1;
			putchar(c);
		}puts("");
	}
}