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

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
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
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<endl;
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

const int N=200010,M=1<<18;
//const int N=4,M=1<<2;
ll n,h[N],prop[M*4+10];
pair<ll,int> seg[M+M*3+10];

pair<ll,int> co(pair<ll,int> a,pair<ll,int> b)
{
	if (a.x>=b.x) return b;
	return a; 
}

void pr(int i)
{
	seg[i].x-=prop[i];
	prop[i*2]+=prop[i];
	prop[i*2+1]+=prop[i];
	prop[i]=0;
}

void pri(pair<ll,int> a)
{
	cout<<a.x<<' '<<a.y<<en;
}

void upd(int i)
{
	i+=M;
	seg[i].x=LLINF;
	vi x={i};
	int ii=i;
	for (i/=2;i;i/=2)
	{
		x.pb(i);
		seg[i]=co(seg[i*2],seg[i*2+1]);
	}
	reverse(x.begin(),x.end());
	for (auto i: x) pr(i),cout<<i<<' ';
	cout<<en;
	i=ii;
	for (i/=2;i;i/=2)
	{
		seg[i]=co(seg[i*2],seg[i*2+1]);
		pri(seg[i]);
	pri(seg[i*2]);
	pri(seg[i*2+1]);
	cout<<en;
	}
}

void upd(int l,int r,ll x,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r)
	{
		prop[i]+=x;
		//cout<<i<<' '<<lo<<' '<<hi<<' '<<prop[i]<<' ';
		//pri(seg[i]);
		pr(i);
		//pri(seg[i]);
		//cout<<en;
		return;
	}
	pr(i);
	if (lo>=r || hi<=l) return;
	int mid=(lo+hi)/2;
	upd(l,r,x,lo,mid,i*2);
	upd(l,r,x,mid,hi,i*2+1);
	seg[i]=co(seg[i*2],seg[i*2+1]);
	//cout<<i<<' '<<lo<<' '<<hi<<en;
	//pri(seg[i]);
	//pri(seg[i*2]);
	//pri(seg[i*2+1]);
	//cout<<en;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	while (cin>>n)
	{
		for (int i=0;i<n;++i)
		{
			cin>>seg[i+M].x;
			seg[i+M].y=i;
		}
		memset(prop,0,sizeof(prop));
		for (int i=n;i<M;++i) seg[i+M].x=LLINF;
		for (int i=M-1;i>0;--i) seg[i]=co(seg[i*2],seg[i*2+1]);
		for (int i=1;i<=n;++i)
		{
			int pos=seg[1].y;
			//cout<<i<<' '<<pos<<en;
			//cout<<"UPD:"<<en;
			upd(pos,pos+1,-LLINF);
			//cout<<seg[1].y<<en;
			//cout<<"PROP:"<<en;
			upd(pos,n,i);
			h[pos]=i;
		}
		for (int i=0;i<n;++i) cout<<h[i]<<' ';
		cout<<endl;
	}
}