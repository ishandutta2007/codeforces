#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

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

ll has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=bases[3];
		h2*=bases[1];
		h2+=a-'a';
		h2%=bases[4];
	}
	return h1*(MOD+13893829)+h2;
}

const int N=300010;
int n,k,h[N],res=1,dpD[N],dpS[N];
vector<int> a[2],z[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
 
int getD(int a)
{
	return dpD[a];
}

int get2(int a)
{
	if (a<=2) return pot(k-1,a);
	return add(mult(k-1,dpS[a-2]),mult(mult(k-1,k-1),dpD[a-2]));
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back((raand()%MOD+13893829)%MOD);
	cin>>n>>k;
	M998();
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
	}
	dpD[0]=dpS[0]=1;
	dpD[1]=k-2;
	dpS[1]=k-1;
	dpD[2]=add(1,mult(k-2,k-1));
	dpS[2]=mult(k-1,k-2);
	for (int i=3;i<=n;++i)
	{
		int pos=mult(k-1,k-1);
		dpD[i]=add(mult(sub(pos,k-2),dpD[i-2]),mult(k-2,dpS[i-2]));
		dpS[i]=add(mult(sub(pos,k-1),dpD[i-2]),mult(k-1,dpS[i-2]));
	}
	for (int i=0;i<n-2;++i) res*=(h[i]<0 || h[i]!=h[i+2]);
	a[0].pb(0);
	a[1].pb(0);
	z[0].pb(0);
	z[1].pb(0);
	for (int i=0;i<n;++i)
	{
		if (h[i]>0) a[i%2].pb(0),z[i%2].pb(h[i]);
		else ++a[i%2][a[i%2].size()-1];
	}
	z[0].pb(-1);
	z[1].pb(-1);
	for (int j=0;j<2;++j)
	{
		if (a[j].size()==1)
		{
			if (a[j][0]) res=mult(res,mult(k,pot(k-1,a[j][0]-1)));
		}
		else
		{
			res=mult(res,get2(a[j][0]));
			res=mult(res,get2(a[j].back()));
			for (int i=1;i<a[j].size()-1;++i)
			{
				if (z[j][i]==z[j][i+1]) res=mult(res,dpS[a[j][i]]);
				else res=mult(res,dpD[a[j][i]]);
			}
		}
		//cout<<res<<endl;
	}
	cout<<res;
}