#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll a,b,c,d;
ll gcd(ll x,ll y)
{ 
    return (x%y==0)?y:gcd(y,x%y);
}
int main()
{
	cin>>a>>b>>c>>d;
	re g=gcd(c,d);
	c/=g,d/=g;
	cout<<min((ll)(a/c),(ll)(b/d));
	return 0;
}