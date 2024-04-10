#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
ll a,b,c,d;
int main()
{	
	cin>>a>>b>>c>>d;
	ll ans=a*2+b*2+c*2+d*2-c*2;
	cout<<ans+4;
    return 0;	
}