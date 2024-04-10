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

const int N=300010,K=62;
int n,up[N],dis[N];
ll h[N];
vi ch[N];
bool bio[401][401];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	vector<int> ex;
	for (ll z=1;z<=1e18;z*=2)
	{
		vi u;
		for (int i=0;i<n;++i) if (h[i]&z) u.pb(i);
		if (u.size()>=3)
		{
			cout<<3;
			exit(0);
		}
		if (u.size()==2) ex.pb(u[1]),ex.pb(u[0]);
	}
	sort(ex.begin(),ex.end());
	for (int i=0;i<n;++i) up[i]=lower_bound(ex.begin(),ex.end(),i)-ex.begin();
	for (ll z=1;z<=1e18;z*=2)
	{
		vi u;
		for (int i=0;i<n;++i) if (h[i]&z) u.pb(i);
		if (u.size()==2) ch[up[u[1]]].pb(up[u[0]]),ch[up[u[0]]].pb(up[u[1]]);
	}
	n=ex.size();
	int mi=MOD;
	for (int i=0;i<n;++i)
	{
		memset(dis,1,sizeof(dis));
		vector<pii> states;
		queue<pair<pii,int>> q;
        q.push({{i,0},-1});
        while (q.size())
        {
            int ii=q.front().x.x,di=q.front().x.y,p=q.front().y;
            q.pop();
            //cout<<ii<<' '<<i<<' '<<di<<' '<<p<<endl;
            if (di>=mi) break;
            if (i==ii && di)
            {
                mi=min(mi,di);
                break;
            }
            if (bio[ii][p]) continue;
            dis[ii]=di;
            bio[ii][p]=1;
            states.pb({ii,p});
            for (auto d: ch[ii]) if (d!=p)
            {
                q.push({{d,di+1},ii});
            }
        }
        for (auto a: states) bio[a.x][a.y]=0;
	}
	if (mi==MOD) cout<<-1;
	else cout<<mi;
}