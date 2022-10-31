#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
string s[5];
int nxt[maxn][27];
void build()
{
	int cur[27];
	memset(cur,0x3f,sizeof(cur));
	for(int i=s[0].length()-1;i>=0;i--)
	{
		for(int j=0;j<27;j++) nxt[i][j]=cur[j];
		cur[s[0][i]-'a']=i;
	}
	for(int i=0;i<27;i++) nxt[maxn-1][i]=cur[i];
}
int dp[253][253][253];
int getpos(int pos,char ch)
{
	if(pos==INF||nxt[pos][ch-'a']==INF) return INF;
	return nxt[pos][ch-'a'];
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	cin>>s[0];
	build();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=maxn-1;
	while(q--)
	{
		char op;
		int tar;
		cin>>op>>tar;
		if(op=='+')
		{
			char ch;
			cin>>ch;
			if(tar==1)
			{
				s[1]+=ch;
				for(int j=0;j<253;j++)
					for(int k=0;k<253;k++)
						dp[s[1].length()][j][k]=INF;
				for(int j=0;j<=s[2].length();j++)
				{
					for(int k=0;k<=s[3].length();k++)
					{
						dp[s[1].length()][j][k]=min(dp[s[1].length()][j][k],getpos(dp[s[1].length()-1][j][k],ch));
						if(j<s[2].length()) dp[s[1].length()][j+1][k]=min(dp[s[1].length()][j+1][k],getpos(dp[s[1].length()][j][k],s[2][j]));
						if(k<s[3].length()) dp[s[1].length()][j][k+1]=min(dp[s[1].length()][j][k+1],getpos(dp[s[1].length()][j][k],s[3][k]));
						dbg(j,k,dp[s[1].length()][j][k]);
					}
				}
			}
			else if(tar==2)
			{
				s[2]+=ch;
				for(int j=0;j<253;j++)
					for(int k=0;k<253;k++)
						dp[j][s[tar].length()][k]=INF;
				for(int j=0;j<=s[1].length();j++)
				{
					for(int k=0;k<=s[3].length();k++)
					{
						dp[j][s[2].length()][k]=min(dp[j][s[2].length()][k],getpos(dp[j][s[2].length()-1][k],ch));
						if(j<s[1].length()) dp[j+1][s[2].length()][k]=min(dp[j+1][s[2].length()][k],getpos(dp[j][s[2].length()][k],s[1][j]));
						if(k<s[3].length()) dp[j][s[2].length()][k+1]=min(dp[j][s[2].length()][k+1],getpos(dp[j][s[2].length()][k],s[3][k]));
					}
				}
			}
			else{
				s[3]+=ch;
				for(int j=0;j<253;j++)
					for(int k=0;k<253;k++)
						dp[j][k][s[tar].length()]=INF;
				for(int j=0;j<=s[1].length();j++)
				{
					for(int k=0;k<=s[2].length();k++)
					{
						dp[j][k][s[3].length()]=min(dp[j][k][s[3].length()],getpos(dp[j][k][s[3].length()-1],ch));
						if(j<s[1].length()) dp[j+1][k][s[3].length()]=min(dp[j+1][k][s[3].length()],getpos(dp[j][k][s[3].length()],s[1][j]));
						if(k<s[2].length()) dp[j][k+1][s[3].length()]=min(dp[j][k+1][s[3].length()],getpos(dp[j][k][s[3].length()],s[2][k]));
					}
				}
			}
		}
		else{
			string tmp="";
			for(int i=0;i<s[tar].size()-1;i++) tmp+=s[tar][i];
			s[tar]=tmp;
		}
		if(dp[s[1].size()][s[2].size()][s[3].size()]<=n||(!s[1].size()&&!s[2].size()&&!s[3].size())) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

}