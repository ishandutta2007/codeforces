/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=998244353;
const int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
template<class T>
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	cout<<w[w.size()-1]<<endl;
}

ll raand()
{
	ll a=rand();
	a*=RAND_MAX;
	a+=rand();
    return a%(MOD-7);
}

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
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

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
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

pair<int,int> has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=MOD;
		h2*=bases[1];
		h2+=a-'a';
		h2%=MOD2;
	}
	return make_pair(h1,h2);
}

const int N=300010;
int n,r=1;
map<pair<ll,int>,int> m;
ll h[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		ll a=round(sqrt((long double)h[i]));
		if (a*a==h[i])
		{
			for (int j=2;j<=round(sqrt(a));++j)
			{
				while (a%j==0)
				{
					a/=j;
					m[mp(j,1)]+=2;
					//cout<<a<<' '<<j<<endl;
				}
			}
			if (a!=1)
			{
				m[mp(a,1)]+=2;
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		ll a=round(sqrt((long double)h[i]));
		if (a*a==h[i]) continue;
		a=round(pow((long double)h[i],1.L/3));
		if (a*a*a==h[i])
		{
			m[mp(a,1)]+=3;
			continue;
		}
		++a;
		if (a*a*a==h[i])
		{
			m[mp(a,1)]+=3;
			continue;
		}
		--a;
		--a;
		if (a*a*a==h[i])
		{
			m[mp(a,1)]+=3;
			continue;
		}
		ll x=1;
		for (int j=0;j<n;++j)
		{
			if (j==i) continue;
			if (h[j]==h[i]) continue;
			if (gcd(h[j],h[i])==1) continue;
			x=gcd(h[j],h[i]);
		}
		if (x==1)
		{
			++m[mp(h[i],2)];
		}
		else
		{
			++m[mp(x,1)];
			++m[mp(h[i]/x,1)];
		}
	}
	for (auto a: m)
	{
		for (int i=0;i<a.first.second;++i) r=mult(r,a.second+1);
		//cout<<a.first.first<<' '<<a.first.second<<' '<<a.second<<endl;
	}
	cout<<r<<endl;
}