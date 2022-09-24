#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

const int N=300010;
int n,xx[N],yy[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

ll solve1()
{
	ordered_set x;
	map<int,int> cnt;
	map<int,vector<int>> p;
	for (int i=0;i<n;++i)
	{
		int a=xx[i],b=yy[i];
		x.insert(a);
		++cnt[a];
		p[b].pb(a);
	}
	ll ans=0;
	for (auto a: p)
	{
		//>previous, <=this
		//multiplied by >=this
		int prev=0,qq=a.y.size();
		sort(a.y.begin(),a.y.end());
		for (auto b: a.y)
		{
			int cnt1=x.order_of_key(b)-(prev==0?-1:x.order_of_key(prev));
			int cnt2=x.size()-x.order_of_key(b);
			//int cnt2=qq;
			//--qq;
			//cout<<b<<' '<<cnt1<<' '<<cnt2<<endl;
			prev=b;
			ans+=cnt1*1ll*cnt2;
		}
		for (auto b: a.y)
		{
			--cnt[b];
			if (cnt[b]==0) x.erase(b);
		}
	}
	return ans;
}

int MAXX=5,MAXY=5,MAXN=5;

ll solve2()
{
	set<vector<int>> s;
	for (int l=0;l<=MAXX;++l) for (int r=l;r<=MAXX;++r) for (int y=0;y<=MAXY+1;++y)
	{
		vector<int> b;
		for (int i=0;i<n;++i) if (xx[i]>=l && xx[i]<=r && yy[i]>=y) b.pb(i);
		s.insert(b);
	}
	return s.size()-1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	bool O=1;
	if (O)
	{
		cin>>n;
		for (int i=0;i<n;++i) cin>>xx[i]>>yy[i];
		cout<<solve1();
	}
	else
	{
		while (1)
		{
			n=rand()%MAXN+1;
			set<pii> s;
			while (s.size()<n) s.insert({rand()%MAXX+1,rand()%MAXY+1});
			vector<pii> w;
			for (auto a: s) w.pb(a);
			shandom_ruffle(w.begin(),w.end());
			for (int i=0;i<n;++i) xx[i]=w[i].x,yy[i]=w[i].y;
			if (solve1()!=solve2())
			{
				cout<<n<<endl;
				for (int i=0;i<n;++i) cout<<xx[i]<<' '<<yy[i]<<endl;
				cout<<solve1()<<' '<<solve2()<<endl;
				exit(0);
			}
		}
	}
}