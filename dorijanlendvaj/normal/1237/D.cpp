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

const int N=300010,M=1<<18;
int n,h[N],seg[M*2+10],s2[M*2+10],p[M*2+10];

void pr(int i)
{
	if (p[i]==-1) return;
	s2[i]=min(s2[i],p[i]);
	if (i<M)
	{
		if (p[i*2]!=-1) p[i*2]=min(p[i*2],p[i]);
		else p[i*2]=p[i];
		if (p[i*2+1]!=-1) p[i*2+1]=min(p[i*2+1],p[i]);
		else p[i*2+1]=p[i];
	}
	p[i]=-1;
}

void upd(int l,int r,int x,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r)
	{
		if (p[i]!=-1) p[i]=min(p[i],x);
		else p[i]=x;
		pr(i);
		return;
	}
	pr(i);
	if (lo>=r || hi<=l) return;
	int mid=(lo+hi)/2;
	upd(l,r,x,lo,mid,i*2);
	upd(l,r,x,mid,hi,i*2+1);
	s2[i]=min(s2[i*2],s2[i*2+1]);
}

int get(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return max(get(l,r,lo,mid,i*2),get(l,r,mid,hi,i*2+1));
}

int g2(int l,int r,int lo=0,int hi=M,int i=1)
{
	pr(i);
	if (lo>=l && hi<=r) return s2[i];
	if (lo>=r || hi<=l) return MOD;
	int mid=(lo+hi)/2;
	return min(g2(l,r,lo,mid,i*2),g2(l,r,mid,hi,i*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	memset(s2,63,sizeof(s2));
	memset(p,-1,sizeof(p));
	for (int i=0;i<n;++i) cin>>h[i],h[i+n]=h[i];
	for (int i=0;i<n*2;++i) seg[i+M]=h[i];
	for (int i=M-1;i>0;--i) seg[i]=max(seg[i*2],seg[i*2+1]);
	int cn=0;
	for (int i=n;i<n*2;++i)
	{
		int lo=-1,hi=i;
		while (lo<hi)
		{
			int mid=(lo+hi+1)/2;
			if (get(mid,i)>h[i]*2) lo=mid;
			else hi=mid-1;
		}
		if (lo!=-1)
		{
			++cn;
			if (lo<n)
			{
				upd(0,lo+1,i);
				upd(lo+1,n,i+n);
			}
			else
			{
				upd(0,lo-n+1,i-n);
				upd(lo-n+1,n,i);
			}
		}
	}
	if (cn==0)
	{
		for (int i=0;i<n;++i) cout<<"-1 ";
		cout<<en;
		exit(0);
	}
	for (int i=0;i<n;++i) cout<<g2(i,i+1)-i<<' ';
}