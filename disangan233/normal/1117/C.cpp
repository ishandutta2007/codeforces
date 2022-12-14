#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
ll a,b,c,d,n,nx,ny,dx[100005],dy[100005];
string s;
int main()
{
	cin>>a>>b>>c>>d>>n;
	ll x=c-a,y=d-b;
	cin>>s;s=' '+s;
	for(re i=1;i<=n;i++)
	{
		if(s[i]=='U') dx[i]=dx[i-1],dy[i]=dy[i-1]+1;
		else if(s[i]=='D') dx[i]=dx[i-1],dy[i]=dy[i-1]-1;
		else if(s[i]=='L') dx[i]=dx[i-1]-1,dy[i]=dy[i-1];
		else dx[i]=dx[i-1]+1,dy[i]=dy[i-1];
	}
	ll l=0,r=1e18,len=n;
	while(l<=r)
	{
		ll mid=(l+r)>>1,tx=x-(mid/len*dx[len]+dx[mid%len]);
		ll ty=y-(mid/len*dy[len]+dy[mid%len]);
		if(abs(tx)+abs(ty)<=mid) r=mid-1;
		else l=mid+1;
	}
	cout<<((l<=1e18)?l:-1);
	return 0;
}