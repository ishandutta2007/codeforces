#pragma GCC optimize("Ofast")

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
#define INF 2e9
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,n1,n2,i;
	int a[6]={4,8,15,16,23,42};
	set<int> se;
	int pro=1;
	set<int> s;
	for(int i=0;i<6;i++)
	{
		pro*=a[i];
		se.insert(a[i]);
		for(int j=0;j<6;j++)
		{
			s.insert(a[i]*a[j]);
		}
	}
	int ans[6];
	cout<<"? 1 1"<<endl;
	cin>>n;
	ans[0]=sqrt(n);pro/=ans[0];
	cout<<"? 2 2"<<endl;cin>>n;ans[1]=sqrt(n);pro/=ans[1];
	cout<<"? 3 4"<<endl;cin>>n1;
	cout<<"? 4 5"<<endl;cin>>n2;
	n=n1*n2;
	for(i=0;i<6;i++)
	{
		if(n%(a[i]*a[i])==0)
		{
			if(s.count(n/(a[i]*a[i])) && se.count(n1/a[i]) && se.count(n2/a[i]) && se.count(pro/(n/a[i])))
			{
				ans[3]=a[i];
				break;
			}
		}
	}
	n/=ans[3];
	ans[2]=n1/ans[3];
	ans[4]=n2/ans[3];
	ans[5]=pro/n;
	cout<<"! ";
	for(i=0;i<6;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}