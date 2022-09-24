#include<bits/stdc++.h>
using namespace std;
const int M=12;
int cnt[1<<M],a[M],n,m,q,dp[(1<<M)][(1<<M)],dpp[(1<<M)][(1<<M)];
int fun(string s)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]-'0')
		sum+=(1<<i);
	}
	return sum;
}
int fn(int x)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(x&(1<<i)) continue;
		else res+=a[i];
	}
	return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++)
	{
		string tmp;
		cin>>tmp;
		cnt[fun(tmp)]++;
	}
	for(int i=0;i<(1<<M);i++)
	{
		for(int j=0;j<(1<<M);j++)
		{
			int vv=fn(i^j);
			dp[i][j]=vv;
			dpp[i][vv]+=cnt[j];
		}
		for(int j=1;j<(1<<M);j++)
		dpp[i][j]+=dpp[i][j-1];
	}
	while(q--)
	{
		string tmp;
		int k,ans=0;
		cin>>tmp>>k;
		int val=fun(tmp);
		cout<<dpp[val][k]<<"\n";
	}
	return 0;
}