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
	
	ll n,d,l,k,lr,rr,i,temp;
	cin>>n>>d>>l;
	lr=((n+1)/2)-(n/2)*l;
	rr=((n+1)/2)*l-(n/2);
	if(d>=lr && d<=rr)
	{
		int a[n];
		for(i=0;i<n;i++)a[i]=1;
		if(n%2)k=d-1;
		else k=d;
		if(k>0)
		{
			temp=k/((n+1)/2);
			for(i=0;i<n;i+=2)
				a[i]+=temp;
			for(i=0;i<2*(k%((n+1)/2));i+=2)
				a[i]++;
		}
		if(k<0)
		{
			k*=-1;
			temp=k/(n/2);
			for(i=1;i<n;i+=2)
				a[i]+=temp;
			for(i=1;i<2*(k%(n/2));i+=2)
				a[i]++;
		}
		for(i=0;i<n;i++)cout<<a[i]<<" ";
	}
	else
		cout<<-1;
	return 0;
}