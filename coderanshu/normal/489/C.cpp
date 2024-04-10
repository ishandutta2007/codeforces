#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int maxc(int &copy)
{
	if(copy>=9)
	{
		copy-=9;return 9;
	}
	else
	{
		int k=copy;
		copy=0;
		return k;
	}
}
int minf(int &copy,int m)
{
	for(auto i=1;i<=9;i++)
	{
		if((copy-i)<=(m-1)*9)
		{
			copy-=i;return i;
		}
	}
}
int minc(int &copy,int m)
{
	for(auto i=0;i<=9;i++)
	{
		if((copy-i)<=(m-1)*9)
		{
			copy-=i;return i;
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,s,copy,i;
	cin>>m>>s;
	if(m==1 && s==0)
	{
		cout<<"0 0";return 0;
	}
	else if(s<1 || s>9*m)
	{
		cout<<"-1 -1";return 0;
	}
	copy=s;
	cout<<minf(copy,m);
	for(i=1;i<m;i++)
		cout<<minc(copy,m-i);
	cout<<" ";
	copy=s;
	for(i=0;i<m;i++)
	{
		cout<<maxc(copy);
	}

	return 0;
}