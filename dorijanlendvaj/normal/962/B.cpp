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

int n,a,b,ab;
char x;
bool ama,amb;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>a>>b;
	ab=a+b;
	for (int i=0;i<n;++i)
	{
		cin>>x;
		if (x=='*')
		{
			ama=0;
			amb=0;
			continue;
		}
		if (a>b && a && b)
		{
			if (!ama)
			{
				--a;
				ama=1;
				amb=0;
			}
			else
			{
				--b;
				ama=0;
				amb=1;
			}
		}
		else if (a && b)
		{
			if (!amb)
			{
				--b;
				amb=1;
				ama=0;
			}
			else
			{
				--a;
				amb=0;
				ama=1;
			}
		}
		else if (a && !ama)
		{
			--a;
			amb=0;
			ama=1;
		}
		else if (b && !amb)
		{
			--b;
			ama=0;
			amb=1;
		}
		else
		{
			ama=0;
			amb=0;
		}
	}
	cout<<ab-a-b<<en;
}