//************************
//*  Date: 2018.9.22     *
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

LL n,x,f,ans=0;
LL a[200010];

bool sot(LL c,LL d)
{
	return c>d;
}

int main()
{
	cin>>n;
	rep(i,n) scanf("%d",&a[i]);
	cin>>x>>f;
	rep(i,n)
	{
		if(a[i]<=x) continue;
		ans+=((a[i]+x+f+f-1)/(x+f)-1)*f;/*
		while(a[i]>x)
		{
			a[i]-=x;
			ans+=f;
			a[i]-=f;
		}*/
	}
	cout<<ans<<endl;
	rt0;
}