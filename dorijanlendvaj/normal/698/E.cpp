//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

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

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
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

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
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

const int N=300010;
int s,m,h,da,d,mo,n;
int dan[]={31,28,31,30,31,30,31,31,30,31,30,31};

int cn(int mo,bool le)
{
	return dan[mo]+(le && mo==1);
}

bool lea(int y)
{
	if (y%400==0) return 1;
	if (y%100==0) return 0;
	if (y%4==0) return 1;
	return 0;
}

int secy(int y)
{
	return (365+lea(y))*86400;
}

int secm(int m,int y)
{
	return cn(m,lea(y))*86400;
}

bool ok(int d1,ll t)
{
	t/=86400;
	int d2=t%7;
	if (da!=-1 && d!=-1) return (d2==da || d1==d);
	else if (da!=-1) return d2==da;
	else if (d!=-1) return d1==d;
	else return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>s>>m>>h>>da>>d>>mo;
	if (da!=-1)
	{
		da+=3;
		da%=7;
	}
	if (d!=-1)
	{
		--d;
	}
	if (mo!=-1)
	{
		--mo;
	}
	cin>>n;
	while (n--)
	{
		ll t;
		cin>>t;
		++t;
		ll c=0,y=1970;
		while (c+secy(y)<=t)
		{
			c+=secy(y);
			++y;
		}
		int cm=0;
		while (c+secm(cm,y)<=t || (mo!=-1 && cm!=mo))
		{
			c+=secm(cm,y);
			++cm;
			if (cm==12) cm=0,++y;
		}
		int cd=0;
		while (c+86400<=t || !ok(cd,c) || (mo!=-1 && cm!=mo))
		{
			c+=86400;
			++cd;
			if (cd==cn(cm,lea(y))) cd=0,++cm;
			if (cm==12) cm=0,++y;
		}
		if (c>=t)
		{
			int ch=0;
			if (h!=-1) ch=h;
			int cm=0;
			if (m!=-1) cm=m;
			int cs=0;
			if (s!=-1) cs=s;
			cout<<c+ch*3600+cm*60+cs<<en;
			continue;
		}
		ll c2=c;
		int ch1=23;
		if (h!=-1) ch1=h;
		int cm1=59;
		if (m!=-1) cm1=m;
		int cs1=59;
		if (s!=-1) cs1=s;
		c2+=ch1*3600+cm1*60+cs1;
		if (c2<t)
		{
			c+=86400;
			++cd;
			if (cd==cn(cm,lea(y))) cd=0,++cm;
			if (cm==12) cm=0,++y;
		}
		while (c+86400<=t || !ok(cd,c) || (mo!=-1 && cm!=mo))
		{
			c+=86400;
			++cd;
			if (cd==cn(cm,lea(y))) cd=0,++cm;
			if (cm==12) cm=0,++y;
		}
		if (c>=t)
		{
			int ch=0;
			if (h!=-1) ch=h;
			int cm=0;
			if (m!=-1) cm=m;
			int cs=0;
			if (s!=-1) cs=s;
			cout<<c+ch*3600+cm*60+cs<<en;
			continue;
		}
		while (1)
		{
			int ctd=t%86400;
			int cs=ctd%60;
			int cm=(ctd%3600)/60;
			int ch=ctd/3600;
			if ((s==-1 || cs==s) && (m==-1 || cm==m) && (h==-1 || ch==h))
			{
				cout<<t<<en;
				break;
			}
			++t;
		}
		//cout<<en;
	}
}