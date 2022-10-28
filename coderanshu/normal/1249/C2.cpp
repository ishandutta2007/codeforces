#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define ll long long 
ll power(ll a,ll b)
{
    if(b==0)
    return (ll)1;
	if(b==1)
		return a;
	return a*power(a,b-1);
}
long long solve(ll n)
{
	ll  a[50],k=0,f=0,i;
	ll temp=n,index;
	while(n!=0)
	{
		a[k++]=n%3;
		n/=3;
	}
	for(i=0;i<k;i++)
	{
		if(a[i]==2)
		{
			f=1;index=i;
		}
	}

	if(!f) return temp;
	f=0;
	for(i=index+1;i<k;i++)
	{
		if(a[i]==0)
		{
			f=1;
			index=i;
			break;
		}
	}
	if(!f)index=k;
	for(i=0;i<index;i++)
		temp-=a[i]*power(3,i);
	temp+=(ll)power(3,index);
	return temp;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n);
		cout<<"\n";
	}
	return 0;
}