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

const int N=300010;
int n,s,t,m;
int p[N],f[N];
int a[N];
vector<int> diff;

int tim(int k)
{
	int ti=0;
	for (auto a: diff)
	{
		if (k<a) return t+1;
		ti+=a*2-min(a,k-a);
	}
	return ti;
}

int bs()
{
	int lo=1,hi=MOD;
	while (lo<hi)
	{
		int mid=(lo+hi)/2;
		if (tim(mid)<=t) hi=mid;
		else lo=mid+1;
	}
	return lo;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for (int i=0;i<n;++i) cin>>p[i]>>f[i];
	int zu=0;
	for (int i=0;i<m;++i)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	for (int i=0;i<m;++i)
	{
		diff.push_back(a[i]-zu);
		zu=a[i];
	}
	diff.push_back(s-zu);
	int mif=bs();
	int mip=2*MOD;
	for (int i=0;i<n;++i) if (f[i]>=mif) mip=min(mip,p[i]);
	if (mip==2*MOD) cout<<-1;
	else cout<<mip;
}