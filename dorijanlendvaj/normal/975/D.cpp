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

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

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

int n,a,b;
map<ll,ll> m,m1,m2,m3;
ll x,o,p,s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>a>>b;
	for (int i=0;i<n;++i)
	{
		cin>>x>>o>>p;
		++m[p-a*o];
		++m1[o];
		++m2[p];
		++m3[(o+MOD-7)*((MOD-7)*2+1)+(p+MOD-7)];
	}
	for (auto z: m)
	{
		s+=(z.second)*(z.second-1);
	}
	/*for (auto z: m1)
	{
		s-=(z.second)*(z.second-1);
	}
	for (auto z: m2)
	{
		s-=(z.second)*(z.second-1);
	}*/
	for (auto z: m3)
	{
		s-=(z.second)*(z.second-1);
	}
	cout<<s<<endl;
}