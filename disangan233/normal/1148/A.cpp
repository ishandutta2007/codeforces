#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int n,m,a[100005];
int main()
{
	ll a,b,c,ans;
	cin>>a>>b>>c;
	if(a!=b) cout<<2ll*min(a,b)+c*2ll+1ll;
	else cout<<2ll*a+2ll*c;
	return 0;
}