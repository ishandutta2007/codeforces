#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b;
	ll x,y;
	cin>>a>>b>>x>>y;
	ll tmp = __gcd(x,y);
	x /= tmp;
	y /= tmp;
	ll m = min(a/x,b/y);
	cout<<m*x<<" "<<m*y<<endl;
	return 0;
}