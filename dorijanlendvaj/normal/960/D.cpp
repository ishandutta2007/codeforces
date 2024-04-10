/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
typedef long long int ll;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"Yes"<<en; exit(0);}
void no() {cout<<"No"<<en; exit(0);}

ll raand()
{
   return rand()*RAND_MAX+rand();
}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<a.size();++i)
	{
		k*=10;
		k+=a[i]-'0';
	}
	return k;
}

string its(ll k)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%10)+'0');
		k/=10;
	}
	reverse(a.begin(),a.end());
	return a;
}

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

ll add(ll a,ll b)
{
	return (a+b)%MOD;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

ll l2(ll a)
{
	ll r=0;
	while (a>1)
	{
		a/=2;
		++r;
	}
	return r;
}

ll a2n(ll a)
{
	ll x=1;
	while (a--)
	{
		x*=2;
	}
	return x;
}

int t;
ll mov[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while (t--)
	{
		ll ti,a,b;
		cin>>ti>>a;
		if (ti==1)
		{
			cin>>b;
			mov[l2(a)+1]-=2*b;
			mov[l2(a)+1]%=a2n(l2(a)+1);
			mov[l2(a)]+=b;
			mov[l2(a)]%=a2n(l2(a));
			/*for (int i=l2(a)+1;i<=60;++i)
			{
				mov[i]-=a2n(i-l2(a))*b;
				mov[i]%=a2n(i);
			}*/
		}
		else if (ti==2)
		{
			cin>>b;
			mov[l2(a)]+=b;
			mov[l2(a)]%=a2n(l2(a));
		}
		else
		{
			while (a)
			{
				cout<<a<<' ';
				int x=l2(a);
				a+=mov[x];
				a%=a2n(x);
				a+=a2n(x);
				a/=2;
			}
			cout<<en;
		}
	}
}