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

LL n,k,sum=0;
LL a[100010]; 

int main()
{
	cin>>n>>k;
	rep(i,n) cin>>a[i],sum+=a[i];
	if(sum%k!=0)
	{
		puts("No");
		rt0;
	}
	int dec=sum/k,last=0;
	sum=0;
	vector <LL> ans;
	rep(i,n)
	{
		sum+=a[i];
		if(i==n-1&&sum!=dec)
		{
			puts("No");
			rt0;
		}
		if(sum==dec)
		{
			sum=0;
			ans.pb(i-last+1);
			last=i+1;
		}
	}
	puts("Yes");
	rep(i,ans.size()) cout<<ans[i]<<' ';
	cout<<endl;
	rt0;
}