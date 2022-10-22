//************************
//*  Date: 2018.10.19    *
//*  Problem:            *
//*  Author: xuziyuan    * 
//************************

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,k;
LL a[200010],must[200010];

int main()
{
	cin>>n>>k;
	rep(i,n) cin>>a[i];
	LL ans=0;
	rep(i,n)
	{
		if(i!=n-1)
		{
			LL p=a[i]/k;
			if(p*k<must[i]) p++;
			ans+=p;
			must[i+1]=max(0LL,a[i]-p*k);
			a[i+1]+=max(0LL,a[i]-p*k);
		}
		else
		{
			ans+=(a[i]+k-1)/k;
		}
	}
	cout<<ans<<endl;
	rt0;
}