#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int n,a,b,c;
typedef long long int ll;

int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

ll mult(ll a,ll b)
{
	return (a*b)%MOD;
}

ll pot(ll n,ll k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

ll divide(ll a,ll b)
{
	return mult(a,pot(b,MOD-2));
}

ll sub(ll a,ll b)
{
	return (a-b+MOD)%MOD;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>c>>a>>b;
	if (a!=1)
	{
		if (b!=n)
		{
			cout<<min(abs(b-c),abs(c-a))+b-a+2<<endl;
		}
		else
		{
			cout<<abs(c-a)+1<<endl;
		}
	}
	else
	{
		if (b!=n) cout<<abs(b-c)+1<<endl;
		else cout<<0<<endl;
	}
}