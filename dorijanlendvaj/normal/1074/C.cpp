/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define rand rund

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
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
	cout<<w[w.size()-1]<<endl;
}

ll raand()
{
	ll a=rand();
	a*=RAND_MAX;
	a+=rand();
    return a;
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
int n,l,r,u,d;
double x1,y1;
int re,re1;
pii po[N],po1[N],po2[N],po3[N],po4[N];
pii sx[N],sy[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

inline int di(int i,int j)
{
	return abs(po[i].x-po[j].x)+abs(po[i].y-po[j].y);
}

bool cmp(pii a,pii b)
{
	long double z1=atan2(a.x-x1,(a.y-y1));
	if (z1<0) z1+=atan(1)*8;
	long double z2=atan2((b.x-x1),(b.y-y1));
	if (z2<0) z2+=atan(1)*8;
	return z1<z2;
}

void try1(int i,int j)
{
	int ma=0;
	for (int k=0;k<n;++k)
	{
		if (k==i || k==j) continue;
		ma=max(ma,di(i,k)+di(i,j)+di(j,k));
	}
	re1=max(re1,ma);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>sx[i].x>>sy[i].x;
		po[i].x=sx[i].x;
		po[i].y=sy[i].x;
		sx[i].y=sy[i].y=i;
		x1+=po[i].x*1./n;
		y1+=po[i].y*1./n;
	}
	for (int i=1;i<n;++i) if (po[i].x<po[l].x) l=i;
	for (int i=1;i<n;++i) if (po[i].x>po[r].x) r=i;
	for (int i=1;i<n;++i) if (po[i].y<po[d].y) d=i;
	for (int i=1;i<n;++i) if (po[i].y>po[u].y) u=i;
	re=di(l,u)+di(u,r)+di(r,d)+di(l,d);
	try1(l,r);
	try1(l,u);
	try1(l,d);
	try1(r,u),
	try1(r,d);
	try1(u,d);
	cout<<re1<<' ';
	for (int i=4;i<=n;++i) cout<<re<<' ';
	cout<<endl;
}