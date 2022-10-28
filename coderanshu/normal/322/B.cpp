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

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll r,g,b,ans,count,tbr,tbg,tbb;
	cin>>r>>g>>b;
	if(r%3==0 && g%3==0 && b%3==0)
	{
		cout<<r/3+b/3+g/3;
	}
	else if(r%3 && b%3 && g%3)
	{
		cout<<r/3+g/3+b/3+min(g%3,min(r%3,b%3));
	}
	else
	{
		count=(r%3==0)+(g%3==0)+(b%3==0);
		if(count==2)
			cout<<r/3+b/3+g/3;
		if(count==1)
		{
			if(r%3==0 && r>0){r-=3;tbr=3;}
			else tbr=r%3;
			if(g%3==0 && g>0){g-=3;tbg=3;}
			else tbg=g%3;
			if(b%3==0 && b>0){b-=3;tbb=3;}
			else tbb=b%3;
			cout<<r/3+g/3+b/3+min(tbb,min(tbr,tbg));
		}
	}

	return 0;
}