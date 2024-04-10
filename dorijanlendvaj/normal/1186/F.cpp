#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pii x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.x + FIXED_RANDOM)^(splitmix64(x.y+FIXED_RANDOM)>>1);
    }
};

const int N=1000010;
int n,m,de[N];
unordered_set<pii,custom_hash> ed;
unordered_set<int> ch[N];
unordered_set<pii,custom_hash> v;
set<pii> p;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void er(int a)
{
    for (auto e: ch[a])
    {
        ed.erase({e,a});
        ed.erase({a,e});
        ch[e].erase(a);
    }
    ch[a].clear();
}

void er(int a,int b)
{
if (v.find({a,b})==v.end()) swap(a, b);
    ed.erase({a,b});
    ch[a].erase(b);
    ch[b].erase(a);
    p.erase({de[a],a});
    p.erase({de[b],b});
    --de[a];
    --de[b];
    if (de[a]) p.insert({de[a],a});
    if (de[b]) p.insert({de[b],b});
    v.erase({a,b});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n>>m;
	for (int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        ed.insert({a,b});
        ch[a].insert(b);
        ch[b].insert(a);
        v.insert({a,b});
        ++de[a];
        ++de[b];
    }
    for (int i=1;i<=n;++i)
    {
        de[i]/=2;
        if (de[i]==0) er(i);
        else p.insert({de[i],i});
    }
    while (p.size())
    {
        auto x=p.rbegin()->y;
//cout<<x<<endl;
        while (ch[x].empty() && p.size())
        {
            p.erase({de[x],x});
            if (p.empty()) break;
            x=p.rbegin()->y;
        }
        if (p.empty()) break;
        auto y=*ch[x].begin();
//cout<<x<<' '<<y<<endl;
        er(x,y);
        if (de[x]==0) er(x);
        if (de[y]==0) er(y);
    }
    cout<<v.size()<<endl;
    for (auto a: v) cout<<a.x<<' '<<a.y<<en;
}