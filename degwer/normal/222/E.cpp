#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll dp[60][52][52];
bool kin[52][52];
ll mod=1000000007;
int hen(char c)
{
	if('a'<=c&&c<='z')
	{
		return c-'a';
	}
	else
	{
		return c-'A'+26;
	}
}
vector<vector<ll> >tim(vector<vector<ll> >m1,vector<vector<ll> >m2)
{
	vector<vector<ll> >ret;
	for(int i=0;i<m1.size();i++)
	{
		vector<ll>damy;
		ret.push_back(damy);
		for(int j=0;j<m1.size();j++)
		{
			ll now=0;
			for(int k=0;k<m1.size();k++)
			{
				now+=m1[i][k]*m2[k][j];
				now%=mod;
			}
			ret[i].push_back(now);
		}
	}
	return ret;
}
vector<vector<ll> >po(vector<vector<ll> >mat,ll a)
{
	vector<int>vec;
	for(;;)
	{
		if(a==0)
		{
			break;
		}
		vec.push_back(a%2);
		a/=2;
	}
	reverse(vec.begin(),vec.end());
	vector<vector<ll> >ret;
	for(int i=0;i<mat.size();i++)
	{
		vector<ll>damy;
		ret.push_back(damy);
		for(int j=0;j<mat.size();j++)
		{
			ret[i].push_back(i==j);
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		ret=tim(ret,ret);
		if(vec[i])
		{
			ret=tim(ret,mat);
		}
	}
	return ret;
}
int main()
{
	ll lon;
	int num,nal;
	vector<vector<ll> >mat;
	scanf("%I64d%d%d",&lon,&num,&nal);
	for(int i=0;i<num;i++)
	{
		vector<ll>damy;
		mat.push_back(damy);
		for(int j=0;j<num;j++)
		{
			mat[i].push_back(1);
		}
	}
	for(int i=0;i<nal;i++)
	{
		char a,b;
		scanf(" %c %c",&a,&b);
		mat[hen(a)][hen(b)]=0;
	}
	vector<vector<ll> >ret=po(mat,lon-1);
	ll ans=0;
	for(int i=0;i<ret.size();i++)
	{
		for(int j=0;j<ret.size();j++)
		{
			ans+=ret[i][j];
			ans%=mod;
		}
	}
	printf("%I64d\n",ans);
}