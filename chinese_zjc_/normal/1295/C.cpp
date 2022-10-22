//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int T,appear[26][100002],cnts[26],lens,lent,last,ans;
string s,t;
int Find(int cnt)
{
	int l=1,r=cnts[cnt]+1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(appear[cnt][mid]<=last)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if(l==cnts[cnt]+1)
	{
		++ans;
		return appear[cnt][1];
	}
	return appear[cnt][l];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>T;
	while(T)
	{
		--T;
		cin>>s>>t;
		lens=s.length();
		lent=t.length();
		fill(cnts,cnts+26,0);
		last=INF;
		ans=0;
		for(int i=0;i<lens;++i)
		{
			appear[s[i]-'a'][++cnts[s[i]-'a']]=i;
		}
		for(int i=0;i<lent;++i)
		{
			if(cnts[t[i]-'a']==0)
			{
				ans=-1;
				break;
			}
			last=Find(t[i]-'a');
		}
		cout<<ans<<endl;
	}
	return 0;
}