#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

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
	ll up=0,lo=0,le=0,ri=0,n,sx,sy,i,x,y;
	cin>>n>>sx>>sy;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		if(x<=sx-1)le++;
		if(x>=sx+1)ri++;
		if(y<=sy-1)lo++;
		if(y>=sy+1)up++;
	}
	ll temp=max(le,max(ri,max(lo,up)));
	cout<<temp<<"\n";
	if(temp==le)
		cout<<sx-1<<" "<<sy;
	else if(temp==ri)
		cout<<sx+1<<" "<<sy;
	else if(temp==up)
		cout<<sx<<" "<<sy+1;
	else
		cout<<sx<<" "<<sy-1;
	return 0;
}