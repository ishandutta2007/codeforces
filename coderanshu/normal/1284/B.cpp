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
#define endl "\n"

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
	ll a[100005],i,n,l,m,j,ans=0,mm,mn,k;
	cin>>n;
	ll t1[n],t2[n];
	k=mn=0;
	for(i=0;i<n;i++)
	{
		cin>>l;
		bool found=false;
		for(j=0;j<l;j++)
			cin>>a[j];
		m=mm=a[0];
		for(j=1;j<l;j++)
		{
			if(a[j]>m)found=true;
			m=min(m,a[j]);
			mm=max(mm,a[j]);
		}
		if(!found)
		{
		t1[k]=m;t2[mn]=mm;k++;mn++;
		}
		else
		{
		ans+=2*n-1;
		}	
	}
	ll le=0,ri=0;
	sort(t2,t2+mn);
	sort(t1,t1+k);
	//cout<<ans;
	while(le<k && ri<mn)
	{
		if(t1[le]<t2[ri])
		{
			ans+=mn-ri;le++;
		}
		else ri++;
	}
	cout<<ans-(n-k)*(n-k)+n-k;
	return 0;
}