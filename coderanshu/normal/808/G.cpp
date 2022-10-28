#include<bits/stdc++.h>
using namespace std ;
#define sz(s) s.size()
#define ll long long 
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

string s,t;
int fuck[100005],pre[100005][26];
void getfuck()//string &s)
{
    size_t n=t.length();
    fuck[0]=0;
    int curLen=0,i=1;
    for(;i<n;)
    {
        if(t[i]==t[curLen])
            fuck[i]=++curLen,++i;
        else{if(curLen==0)fuck[i]=0,++i;
            else curLen=fuck[curLen-1];}}
}
void preprocess()
{
	size_t n = t.length();
	for(int i=0;i<26;++i)
	{
		char ch='a'+i;
		for(int j=0;j<n;++j)
		{
			if(ch==t[j])
				pre[j][i]=j+1;
			else
			{
				ll x=j;
				x=fuck[x-1];
				pre[j][i]=pre[x][i];
				/*while(x>0 && ch!=t[x])
					x=fuck[x-1];
				if(ch==t[x])
					++x;
				pre[j][i]=x;*/
			}
		}
	}
}
int _runtimeTerror_()
{
	cin>>s>>t;
	getfuck();
	int n=sz(s);
	preprocess();
	int i,j,k,l;
	vector<vector<int>> dp(sz(s)+1,vector<int> (sz(t)+1,-1));
	dp[0][0]=0;
	int len=sz(t);
	for(i=1;i<=n;++i)
	{
		for(j=0;j<len;++j)
		{
			if(dp[i-1][j]==-1)continue;
			for(k=0;k<26;++k)
			{
				if(s[i-1]=='?' || s[i-1]==(char)(k+'a'))
				{
					int val=pre[j][k];
					int ff=0;
					if(val==len)
						val=fuck[val-1],++ff;
					amax(dp[i][val],dp[i-1][j]+ff);
				}
			}
		}
	}
	ll ans=0;
	for(j=0;j<len;++j)
		amax(ans,dp[n][j]);
	cout<<ans<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}