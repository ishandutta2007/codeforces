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

const int N=400010,M=1<<19;
int n;
pii a[N],b[N];
ll ov[N];
map<int,int> co;
vector<pii> ev[N];
int seg[5][M*2+10];

void upd(int i,int j,int x)
{
	for (i+=M;i;i/=2)
	{
		seg[j][i]+=x;
		if (seg[j][i]<0) seg[j][i]+=MOD;
		if (seg[j][i]>=MOD) seg[j][i]-=MOD;
	}
}

int ge(int l,int r,int j,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[j][i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return add(ge(l,r,j,lo,mid,i*2),ge(l,r,j,mid,hi,i*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	//bases.pb(2);
	//bases.pb(3);
	//cout<<(bases[0]+0ll+pot(bases[0],2)+pot(bases[0],3)+pot(bases[0],4))%MOD<<en;
	//cout<<(bases[1]+0ll+pot(bases[1],2)+pot(bases[1],3)+pot(bases[1],4))%MOD<<en;
	cin>>n;
	set<int> s;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
		a[i].x*=2;
		a[i].y*=2;
		b[i].x*=2;
		b[i].y*=2;
		++a[i].y;
		++b[i].y;
		s.insert(a[i].x);
		s.insert(a[i].y);
		s.insert(b[i].x);
		s.insert(b[i].y);
		/*ev.pb({a[i].x,i});
		ev.pb({a[i].y,-i});
		ev.pb({b[i].x,i+n});
		ev.pb({b[i].y,-i-n});*/
	}
	vi v(s.begin(),s.end());
	for (int i=0;i<v.size();++i) co[v[i]]=i;
	for (int i=1;i<=n;++i)
	{
		a[i].x=co[a[i].x];
		a[i].y=co[a[i].y];
		b[i].x=co[b[i].x];
		b[i].y=co[b[i].y];
	}
	for (int i=1;i<=n;++i)
	{
		ev[a[i].x].eb(a[i].y,i);
		ev[a[i].y].eb(a[i].x,-i);
		ev[b[i].x].eb(b[i].y,i+n);
		ev[b[i].y].eb(b[i].x,-i-n);
	}
	int c11=0,c12=0,c21=0,c22=0;
	for (int o=0;o<=n*4;++o)
	{
		for (auto a: ev[o])
		{
			if (a.y>0)
			{
				if (a.y>n)
				{
					//cout<<a.x<<' '<<o<<' '<<a.y<<" 3ope "<<seg[3][a.x+M]<<' ';
					c21=add(c21,pot(bases[0],a.y-n));
					c22=add(c22,pot(bases[1],a.y-n));
					upd(a.x,2,pot(bases[0],a.y-n));
					upd(a.x,3,pot(bases[1],a.y-n));
					//cout<<seg[3][a.x+M]<<en;
				}
				else
				{
					//cout<<a.x<<' '<<o<<' '<<a.y<<" 1ope "<<seg[1][a.x+M]<<' ';
					c11=add(c11,pot(bases[0],a.y));
					c12=add(c12,pot(bases[1],a.y));
					upd(a.x,0,pot(bases[0],a.y));
					upd(a.x,1,pot(bases[1],a.y));
					//cout<<seg[1][a.x+M]<<en;
				}
			}
			else
			{
				a.y=-a.y;
				if (a.y>n)
				{
					//cout<<a.x<<' '<<o<<' '<<a.y<<" 3clo "<<seg[3][o+M]<<' ';
					c21=sub(c21,pot(bases[0],a.y-n));
					c22=sub(c22,pot(bases[1],a.y-n));
					upd(o,2,MOD-pot(bases[0],a.y-n));
					upd(o,3,MOD-pot(bases[1],a.y-n));
					//cout<<seg[3][o+M]<<en;
				}
				else
				{
					//cout<<a.x<<' '<<o<<' '<<a.y<<" 1clo "<<seg[1][o+M]<<' ';
					c11=sub(c11,pot(bases[0],a.y));
					c12=sub(c12,pot(bases[1],a.y));
					upd(o,0,MOD-pot(bases[0],a.y));
					upd(o,1,MOD-pot(bases[1],a.y));
					//cout<<seg[1][o+M]<<en;
				}
			}
		}
		for (auto a: ev[o])
		{
			if (a.y>0)
			{
				if (a.y>n)
				{
					ov[a.y]+=sub(c21,ge(a.x+1,N,2))*3ll*MOD+sub(c22,ge(a.x+1,N,3));
					//cout<<sub(c22,ge(a.x+1,N,3))<<en;
				}
				else
				{
					ov[a.y]+=sub(c11,ge(a.x+1,N,0))*3ll*MOD+sub(c12,ge(a.x+1,N,1));
					//cout<<sub(c12,ge(a.x+1,N,1))<<en;
				}
			}
			else
			{
				a.y=-a.y;
				if (a.y>n)
				{
					ov[a.y]+=c21*3ll*MOD+c22;
					//cout<<c21<<' '<<c22<<en;
				}
				else
				{
					ov[a.y]+=c11*3ll*MOD+c12;
					//cout<<c11<<' '<<c12<<en;
				}
			}
		}
	}
	//for (int i=1;i<=n;++i) cout<<"1 "<<i<<' '<<ov[i]/3/MOD<<' '<<ov[i]%(3ll*MOD)<<en;
	//for (int i=1+n;i<=n+n;++i) cout<<"2 "<<i-n<<' '<<ov[i]/3/MOD<<' '<<ov[i]%(3ll*MOD)<<en;
	//memset(seg,0,sizeof(seg));
	for (int o=n*4;o>=0;--o)
	{
		for (auto a: ev[o])
		{
			if (a.y>0)
			{
				if (a.y>n)
				{
					ov[a.y]+=ge(0,a.x+1,2)*3ll*MOD+ge(0,a.x+1,3);
				}
				else
				{
					ov[a.y]+=ge(0,a.x+1,0)*3ll*MOD+ge(0,a.x+1,1);
				}
			}
		}
		for (auto a: ev[o])
		{
			if (a.y>0)
			{
				if (a.y>n)
				{
					upd(a.x,2,pot(bases[0],a.y-n));
					upd(a.x,3,pot(bases[1],a.y-n));
					//cout<<seg[3][a.x+M]<<en;
				}
				else
				{
					upd(a.x,0,pot(bases[0],a.y));
					upd(a.x,1,pot(bases[1],a.y));
					//cout<<seg[1][a.x+M]<<en;
				}
			}
		}
	}
	//for (int i=1;i<=n;++i) cout<<"1 "<<i<<' '<<ov[i]/3/MOD<<' '<<ov[i]%(3ll*MOD)<<en;
	//for (int i=1+n;i<=n+n;++i) cout<<"2 "<<i-n<<' '<<ov[i]/3/MOD<<' '<<ov[i]%(3ll*MOD)<<en;
	for (int i=1;i<=n;++i) if (ov[i]%MOD!=ov[i+n]%MOD || (ov[i]/3/MOD)%MOD!=(ov[i+n]/3/MOD)%MOD) no();
	yes();
}