/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
const int BASE=29;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

ll raand()
{
   return rand()*RAND_MAX+rand();
}

string to_upper(string a)
{
	for (int i=0;i<a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
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

pair<int,int> has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (auto a: x)
	{
		h1*=BASE;
		h1+=a-'a';
		h1%=MOD;
		h2*=BASE;
		h2+=a-'a';
		h2%=MOD2;
	}
	return {h1,h2};
}

const ll N=10000;
ll n;
ll o;
map<ll,string> a;
string pro;
map<ll,bool> postoji;

int le(ll x)
{
	if (postoji.find(x)!=postoji.end()) return a[x].size();
	if (x<10) return 1;
	if (x<100) return 2;
	if (x<1000) return 3;
	if (x<10000) return 4;
	if (x<100000) return 5;
	if (x<1000000) return 6;
	if (x<10000000) return 7;
	if (x<100000000) return 8;
	if (x<1000000000) return 9;
	if (x<10000000000ll) return 10;
	return 11;
}

void try1(ll x,string y)
{
	if (x==n)
	{
		if (!pro.size() || y.size()<pro.size()) pro=y;
		return;
	}
	if (pro.size() && y.size()+1+le(n-x)>=pro.size()) return;
	pro=y;
	if (y.size()) pro.push_back('+');
	if (postoji.find(n-x)!=postoji.end()) pro.append(a[n-x]);
	else pro.append(its(n-x));
}

vector<pair<ll,int> > ler;
vector<pair<ll,int> > v;

int mok(ll z)
{
    for (auto x: ler)
    {
        if (x.first>z) return x.second;
    }
    return ler[ler.size()-1].second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	//try1(1296,"6^4");
	//cout<<pro<<endl;
	for (ll y=2;y<=100000;++y)
	{
		int q=its(y).size();
		ll e=y*y;
		for (ll z=2;e<=n;++z)
		{
			int l=1+q+its(z).size();
			if (l<its(e).size())
			{
				if (!bool(a[e].size()) || a[e].size()>l)
				{
					string d=its(y);
					d.push_back('^');
					d.append(its(z));
					a[e]=d;
					v.push_back({e,l});
					postoji[e]=1;
				}
			}
			e*=y;
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int mir=11;
	for (auto x: v)
	{
	    if (x.second<mir)
	    {
	        mir=x.second;
	        ler.push_back({x.first,mir});
	    }
	}
	ler.push_back({99,2});
	ler.push_back({9,1});
	ler.push_back({0,0});
	reverse(ler.begin(),ler.end());
	try1(0,"");
	double t=clock();
	for (auto x: a)
	{
		if (!x.second.size()) continue;
		ll e=x.first;
		string u=x.second;
		//cout<<e<<' '<<u<<endl;
		try1(e,u);
		int p=u.size();
		int le2=1;
		if (its(e).size()<=u.size()+1) continue;
		int bu=n/x.first;
		while (bu>0 && mok(n-bu*x.first)+le(bu)+2+p<=pro.size()) --bu;
		int lu=max(1,bu-1);
		//if (u=="9^9") cout<<bu<<endl;
		for (ll r=x.first*max(2,bu);r<=n;r+=x.first)
		{
			++lu;
			le2=le(lu);
			if (r!=n)
			{
				if (pro.size() && le2+1+p+1+le(n-r)>=pro.size()) continue;
			}
			string z=its(lu);
			if (a[lu].size()) z=a[lu];
			z.push_back('*');
			z.append(u);
			try1(r,z);
			//if (u=="5^6") cout<<r<<' '<<lu<<' '<<z<<' '<<e<<' '<<x.first<<endl;
		}
	}
	cout<<pro<<endl;
}