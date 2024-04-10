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

int n,k;
string h;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k>>h;
	if (k>n)
	{
		cout<<h;
		sort(h.begin(),h.end());
		for (int i=0;i<k-n;++i) cout<<h[0];
	}
	else
	{
		if (k==1)
		{
			string k=h;
			sort(h.begin(),h.end());
			cout<<*upper_bound(h.begin(),h.end(),k[0])<<endl;
		}
		else
		{
			string p=h;
			sort(p.begin(),p.end());
			int o=k-1;
			for (;h[o]==p[p.size()-1];--o);
			for (int i=0;i<o;++i) cout<<h[i];
			cout<<*upper_bound(p.begin(),p.end(),h[o]);
			for (int i=o+1;i<k;++i) cout<<p[0];
			cout<<endl;
		}
	}
}